# My Zephyr workspace
[![.github/workflows/build.yml](https://github.com/mbober1/ZephyrOS_workspace/actions/workflows/build.yml/badge.svg?branch=master)](https://github.com/mbober1/ZephyrOS_workspace/actions/workflows/build.yml)

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
