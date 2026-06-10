# Rainmeter Connection Monitor

A minimal Rainmeter skin that displays ping status for any server or host with a color-coded indicator.

![Status: Online](https://img.shields.io/badge/status-online-brightgreen) ![License: MIT](https://img.shields.io/badge/license-MIT-blue)

## Preview

| Status | Color | Condition |
|--------|-------|-----------|
| 🟢 Online | Green | Ping between 1–49 ms |
| 🟡 High latency | Yellow | Ping between 50–499 ms |
| 🔴 Offline | Red | No response |

![Preview](preview.png)
## Requirements

- [Rainmeter](https://www.rainmeter.net/) 4.0 or later

## Installation

1. Download or clone this repository into your Rainmeter Skins folder:
   ```
   C:\Users\<YourName>\Documents\Rainmeter\Skins\ConnectionMonitor
   ```
2. Open Rainmeter, go to **Manage → Skins** and load the desired skin (e.g. `Casper/Casper.ini`).

## Adding a new server

1. Copy an existing server folder (e.g. `Casper/`) and rename it to your server's name.
2. Open the `.inc` file inside and update the variables:

```ini
[Variables]
ServerIP=192.168.0.1       ; IP address or hostname
ServerName=MyServer        ; Display name
PingGreenMax=50            ; Below this (ms) = green
PingYellowMax=500          ; Below this (ms) = yellow, above = red
```

3. Rename the `.ini` file inside the folder to match the folder name.
4. Open the `.ini` file and update the `@Include2` line to point to your new `.inc` file:

```ini
[Variables]
@Include2=MyServer.inc
```

5. Load the new skin in Rainmeter.

## Project Structure

```
ConnectionMonitor/
├── @Resources/
│   └── ConnectionMonitor.inc   ← core logic, do not edit
├── Casper/
│   ├── Casper.ini
│   └── Casper.inc              ← server config
├── Demo1/
│   ├── Demo1.ini
│   └── Demo1.inc
└── Demo2/
    ├── Demo2.ini
    └── Demo2.inc
```

## License

MIT — feel free to use, modify, and distribute.
