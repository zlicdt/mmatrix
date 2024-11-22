default:
	@mkdir -p bin
	@echo "[CXX] src/main.cpp"
	@g++ src/main.cpp -o bin/mmatrix
clean:
	@echo "[CLEAN] bin/mmatrix"
	@rm -r bin
install:
	@echo "[INSTALL] mmatrix"
	@sudo cp bin/mmatrix /usr/bin/mmatrix
uninstall:
	@echo "[UNINSTALL] mmatrix"
	@sudo rm /usr/bin/mmatrix
