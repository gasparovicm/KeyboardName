# KeyboardName

This repository contains implementations of a keyboard layout detector in both C# (.NET) and C++.
- I had some problems with detection of Slovak QWERTY an QWERTZ keyboards.

## Projects

### KeyboardName (C#)
- **Framework**: .NET 10
- **Type**: Console Application
- **Description**: Detects the active keyboard layout using Windows API.

### KeyboardNameCpp (C++)
- **Type**: Console Application
- **Description**: C++ version of the keyboard layout detector using Windows API.

## Features
- Detects the current keyboard layout (e.g., Slovak QWERTY, QWERTZ, etc.).
- Uses Windows user32.dll functions to retrieve layout information.

## Requirements
- Windows OS
- For C#: .NET 10 SDK
- For C++: Visual Studio with C++ build tools

## Building and Running

### C# Project
1. Open the solution in Visual Studio.
2. Set `KeyboardName` as the startup project.
3. Build and run.

Or via command line:
```
cd KeyboardName
dotnet build
dotnet run
```

### C++ Project
1. Open the solution in Visual Studio.
2. Set `KeyboardNameCpp` as the startup project.
3. Build and run.

## Usage
Both applications output the detected keyboard layout name to the console.

## Contributing
Feel free to submit issues or pull requests.

## License
MIT License