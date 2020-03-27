libraries:
	mkdir -p libs
	wget -O libs/stack.h https://raw.githubusercontent.com/ss-c-cpp/stack/master/src/stack.h
	wget -O libs/libstack.a https://raw.githubusercontent.com/ss-c-cpp/stack/master/lib/libstack.a

run:
	gcc -static -o $(exercise) $(exercise).c -L./libs -lstack
	./$(exercise)
