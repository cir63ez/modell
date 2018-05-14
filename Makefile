# C Compiling Options

# C Compiler executable
CC=gcc
# Folder where the C project is
CROOT=renderer
# Compilation flags (-l: links libraries (-lm: links math), -Wall: show all warnings)
CFLAGS?=-lm -Wall
# Main file in the "CROOT" folder ($(CROOT)/$(TARGET).c)
TARGET?=renderer
# Local libraries files needed for the compilation (LOCAL_LIBS=lib1.o lib2.o lib3.o) -	They will be automatically compiled
LOCAL_LIBS?=lib.o

# PHP Server Options

# PHP interpreter
PHP=php
# Folder where the PHP project is
PHPROOT=server
# Server port
PORT?=8080
# Server host (use localhost or public ip - or local for LAN/hotspot sharing)
HOST?=localhost

# Recipes

install:
	sudo apt-get install -y php
	sudo apt-get install -y php-dev
	sudo apt-get install -y gcc
	sudo apt-get install -y libsdl1.2debian
	sudo apt-get install -y libsdl2-2.0.0
	sudo apt-get install -y libsdl1.2-dev
	sudo apt-get install -y libsdl2-dev
	sudo apt-get install -y libsdl-image1.2
	sudo apt-get install -y libsdl-image1.2-dev

$(LOCAL_LIBS): %.o: $(CROOT)/%.c $(CROOT)/%.h
	$(CC) -c $< -o $(CROOT)/$@

build: $(CROOT)/$(TARGET).c $(LOCAL_LIBS)
	cd $(CROOT); $(CC) $(TARGET).c $(CFLAGS) -o $(TARGET) $(LOCAL_LIBS)

run: build
	./$(CROOT)/$(TARGET)

serve:
	$(PHP) -S $(HOST):$(PORT) -t $(PHPROOT)

clean:
	find $(CROOT) -type f ! -name "*.*" ! -path "./Makefile" -delete
	find $(CROOT) -type f -name "*out*" -delete
	rm $(CROOT)/*.o