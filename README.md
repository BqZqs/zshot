# zshot

> 丐版 flameshot - 轻量级 Windows 像素风截图工具

zshot 是一个轻量级的 Windows 截图工具，基于 flameshot 精简而来。保留了核心的截图标注功能，采用像素风格界面和少女粉主题。

## 功能

- **自由绘制** - 在截图上自由涂鸦
- **马赛克** - 像素化敏感信息
- **矩形工具** - 绘制矩形框选
- **圆形工具** - 绘制圆形/椭圆标注
- **Pin 功能** - 将截图固定到桌面
- **16 种预设颜色** - 快速选择画笔颜色
- **截图窗口移动与缩放** - 自由调整截图区域

## 界面主题

像素风格（8-bit retro），少女粉配色：
- 主色: `#FFB6C1` (浅粉)
- 强调色: `#FF69B4` (热粉)
- 深色: `#FF1493` (深粉)

## 下载

从 [Releases](https://github.com/zshot-org/zshot/releases) 页面下载最新的 `zshot-*-win64.zip` 便携压缩包。

解压后直接运行 `zshot.exe` 即可使用。

## 构建

### 依赖

- Windows 10/11
- Visual Studio 2022
- CMake 3.22+
- Qt 6.5+

### 编译

```powershell
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cpack -G ZIP
```

## 许可

GPL-3.0

## 致谢

本项目基于 [flameshot](https://github.com/flameshot-org/flameshot) 精简而来，感谢原项目的开发者们。
