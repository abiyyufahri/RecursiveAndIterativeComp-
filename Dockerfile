# Python image
FROM python:3.9-slim

WORKDIR /app

# Install dependensi
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Menyalin semua file aplikasi ke dalam container
COPY . .

# Menjalankan aplikasi Flask
CMD ["python", "app.py"]