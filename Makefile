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
LOCAL_LIBS?=bmp.o lib.o file.o raytracer.o objects.o

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
	sudo apt-get install -y gcc
	sudo apt-get install -y php
	sudo apt-get install -y php-dev

$(LOCAL_LIBS): %.o: $(CROOT)/%.c $(CROOT)/%.h
	$(CC) -c $< -o $(CROOT)/$@

build: $(CROOT)/$(TARGET).c $(LOCAL_LIBS)
	cd $(CROOT); $(CC) $(TARGET).c -o $(TARGET) $(LOCAL_LIBS) $(CFLAGS)

run: build
	./$(CROOT)/$(TARGET)

dev-serve:
	$(PHP) -c /etc/php/7.2/apache2/php.ini -S $(HOST):$(PORT) -t $(PHPROOT)

serve:
	$(PHP) -S $(HOST):$(PORT) -t $(PHPROOT)

clean:
	find $(CROOT) -type f ! -name "*.*" ! -path "./Makefile" -delete
	find $(CROOT) -type f -name "*out*" -delete
	find $(CROOT) -type f -name "*.o" -delete
	find $(CROOT) -type f -name "*.bmp" -delete
	find $(PHPROOT) -type f -name "*.bmp" -delete
	find . -type f -name "*.bmp" -delete
	find . -type f -name "data.txt" -delete