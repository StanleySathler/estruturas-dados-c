LIBS_DIR=libs
INCLUDES_DIR=libs/include

libraries:
	mkdir -p $(LIBS_DIR)
	mkdir -p $(INCLUDES_DIR)
	wget -O $(INCLUDES_DIR)/stack.h https://raw.githubusercontent.com/ss-c-cpp/stack/master/src/stack.h
	wget -O $(LIBS_DIR)/libstack.a https://raw.githubusercontent.com/ss-c-cpp/stack/master/lib/libstack.a

run:
	gcc -g -static -o $(exercise).out $(exercise).c -I./libs -L./libs -lstack
	./$(exercise).out
