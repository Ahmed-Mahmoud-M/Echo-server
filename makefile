client:
	@g++ .\ClientSocket.cpp -o client -lws2_32

	@./client



server:
	@g++ .\ServerSocket.cpp -o server -lws2_32
	@/server



remove:
	@rm .\client.exe
	@rm .\server.exe








