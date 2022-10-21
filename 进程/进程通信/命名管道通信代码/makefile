.PHONY:all
all:write read
write:write_pipe.c
	gcc -o $@ $^
read:read_pipe.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -rf write read Mypipe
