import requests

ESP_IP = "http://192.168.4.1"  # Change to your ESP8266 IP

def send_gesture(text_response):
    gesture = classify_gesture(text_response)
    try:
        requests.get(f"{ESP_IP}/gesture?cmd={gesture}", timeout=1)
    except Exception as e:
        print("Failed to send gesture:", e)

def classify_gesture(text):
    text = text.lower()
    if "!" in text or "happy" in text:
        return "nod"
    elif "sorry" in text or "sad" in text:
        return "tilt"
    else:
        return "idle"