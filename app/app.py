from flask import Flask, request, jsonify, render_template # type: ignore

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

    
    result_iterative = run(f"./programs/out {param}", shell=True, capture_output=True, text=True)
    result_iterative = result_iterative.stdout.strip()
    result_iterative = str(result_iterative).split('\n')
    execution_time_iterative = result_iterative[1]

    result_recursive = run(f"./programs/rr {param}", shell=True, capture_output=True, text=True)
    result_recursive = result_recursive.stdout.strip()
    result_recursive = str(result_recursive).split('\n')
    execution_time_recursive = result_recursive[0]

    n = str(len(param))
    return jsonify({
        'n': n,
        'iterative' : {
                'step': result_iterative[0],
                'run_time': execution_time_iterative
            },
        'recursive' : {
            'step': result_recursive[1],
            'run_time': execution_time_recursive
            }
    })

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)