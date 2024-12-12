from flask import Flask, request, jsonify, render_template

from subprocess import run


app = Flask(__name__)

@app.route('/', methods=['GET'])
def handle_get():
    return render_template('index.html')

@app.route('/', methods=['POST'])
def handle_post():
    param = request.form.get('input', default='0', type=str)

    result = run(f"./out {param}", shell=True, capture_output=True, text=True)
    return jsonify({
        'step': result.stdout.strip(),
        'n': str(len(param)),
    })

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)