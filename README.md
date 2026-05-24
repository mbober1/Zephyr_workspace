# My Zephyr workspace

- [x] Devcontainer environment
- [x] VSCode configs
- [x] JLink support
- [x] Zephyr app template
- [x] CI/CD pipeline (GitHub Actions)

## Setup and build
```
west init --local app
west update
west build -b weact_stm32g431_core app
```
