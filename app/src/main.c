#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/input/input.h>

K_MSGQ_DEFINE(button_action_msgq, sizeof(int), 16, 4);

void button_action_work_handler(struct k_work *work) {
	while (k_msgq_num_used_get(&button_action_msgq)) {
	uint32_t button_states;
		k_msgq_get(&button_action_msgq, &button_states, K_NO_WAIT);
		printf("Button states: %d\n", button_states);
		k_yield();
	}
}

K_WORK_DEFINE(button_action_work, button_action_work_handler);

static void button_input_cb(struct input_event *evt, void *user_data)
{
	k_msgq_put(&button_action_msgq, &(evt->value), K_NO_WAIT);
	k_work_submit(&button_action_work);
}

INPUT_CALLBACK_DEFINE(NULL, button_input_cb, NULL);

int main(void)
{
	while (1) {
		k_sleep(K_FOREVER);
	}
	return 0;
}

FUNC_NORETURN __weak void arch_system_halt(unsigned int reason)
{
	ARG_UNUSED(reason);

	(void)arch_irq_lock();
	for (;;) {
		__asm("bkpt #0");
	}
}