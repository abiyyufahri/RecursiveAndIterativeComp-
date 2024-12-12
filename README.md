### requirement
* Niat
* Docker

### how to use

#### saat pertama kali dijalankan
Akan sedikit lama tergantung jaringan masing-masing
```
docker build --tag img_server_aka:1.0 .
```

#### menjalankan server
```
docker compose up -d
```
setelah itu dapat dibuka pada
`http://localhost`

#### mematikan server
```
docker compose down
```
