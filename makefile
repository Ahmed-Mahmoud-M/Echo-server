client:
	@g++ ClientSocket.cpp -o client -lws2_32
	@./client.exe



server:
	@g++ ServerSocket.cpp -o server -lws2_32
	@./server.exe



remove:
	@rm .\client.exe
	@rm .\server.exe








