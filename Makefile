LIBS_DIR=libs
INCLUDES_DIR=libs/include

libraries:
	mkdir -p $(LIBS_DIR)
	mkdir -p $(INCLUDES_DIR)
	wget -O $(INCLUDES_DIR)/stack.h https://raw.githubusercontent.com/ss-c-cpp/stack/master/lib/stack.h
	wget -O $(LIBS_DIR)/libstack.a https://raw.githubusercontent.com/ss-c-cpp/stack/master/lib/libstack.a
	wget -O $(INCLUDES_DIR)/queue.h https://raw.githubusercontent.com/ss-c-cpp/queue/master/lib/queue.h
	wget -O $(LIBS_DIR)/libqueue.a https://raw.githubusercontent.com/ss-c-cpp/queue/master/lib/libqueue.a
	wget -O $(INCLUDES_DIR)/assert.h https://raw.githubusercontent.com/ss-c-cpp/assert/master/lib/assert.h
	wget -O $(LIBS_DIR)/libassert.a https://raw.githubusercontent.com/ss-c-cpp/assert/master/lib/libassert.a

run:
	gcc -g -static -o \
		$(exercise).out $(exercise).test.c $(exercise).c \
		-I./libs -L./libs \
		-lstack \
		-lassert \
		-lqueue
	./$(exercise).out

add:
	mkdir -p $(chapter)/$(exercise)
	cat templates/exec-c.txt >> $(chapter)/$(exercise)/$(exercise).c
	cat templates/exec-h.txt >> $(chapter)/$(exercise)/$(exercise).h
	cat templates/exec-test.txt >> $(chapter)/$(exercise)/$(exercise).test.c
