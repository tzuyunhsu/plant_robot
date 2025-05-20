# ChatGestureBot

🌱 A chatbot that interacts with humans using expressive gestures via an ESP8266 servo controller. Hosted on Raspberry Pi or PC.

## Features

- Web-based chatbot UI (Flask)
- Local LLM fallback using HuggingFace DialoGPT
- Gesture control via ESP8266 (serial or Wi-Fi)
- Works on Raspberry Pi or your main computer

## Setup Instructions

### ESP8266 Firmware

1. Open `gesture_firmware/gesture_esp8266.ino` in Arduino IDE
2. Flash it to your ESP8266 with Wi-Fi credentials
3. Plug servo into D1 (or change in code)

### Flask Web Server

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
cd chatbot
python app.py
```

Then open `http://localhost:5000` or your Pi IP.