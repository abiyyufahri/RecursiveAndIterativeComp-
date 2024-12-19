from flask import Flask, request, jsonify, render_template

from subprocess import run
from time import time

app = Flask(__name__)
app.config['MAX_CONTENT_LENGTH'] = 10 * 1024 * 1024

@app.route('/', methods=['GET'])
def handle_get():
    return render_template('index.html')

@app.route('/', methods=['POST'])
def handle_post():
    param = request.form.get('input')

    
    start_time = time()
    result_iterative = run(f"./programs/out {param}", shell=True, capture_output=True, text=True)
    end_time = time()
    execution_time_iterative = end_time - start_time  # Waktu eksekusi dalam detik

    start_time = time()
    result_recursive = run(f"./programs/rr {param}", shell=True, capture_output=True, text=True)
    end_time = time()
    execution_time_recursive = end_time - start_time

    n = str(len(param))
    return jsonify({
        'n': n,
        'iterative' : {
                'step': result_iterative.stdout.strip(),
                'run_time': execution_time_iterative
            },
        'recursive' : {
            'step': result_recursive.stdout.strip(),
            'run_time': execution_time_recursive
            }
    })

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)