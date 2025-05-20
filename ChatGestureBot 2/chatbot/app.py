from flask import Flask, request, render_template
from gpt_chat import generate_response
from gesture_trigger import send_gesture

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def chat():
    response = ""
    if request.method == "POST":
        user_input = request.form["message"]
        response = generate_response(user_input)
        send_gesture(response)
    return render_template("index.html", response=response)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000, debug=True)