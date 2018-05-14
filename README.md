# Modell

## Makefile

Before all, make sure to have **make** installed:

```bash
sudo apt-get install make -y
```


### Renderer compilation

Edit needed local libraries in the **Makefile**:

```Makefile
LOCAL_LIBS?=lib1.o lib2.o lib3.o
```

To build the project, run:

```bash
make build
```

#### Arguments

- LOCAL_LIBS: Libraries to compile (With .o extension: "lib.o")
- CFLAGS: Compilation flags
- TARGET: Name of the main file (compilation target, containing the main function)

Exemples:

```bash
make build CFLAGS=-lm -Wall -g
make build TARGET=test LOCAL_LIBS=mylib.o lib2.o
```

### Run PHP Server

```php
make serve
```

#### Arguments

- PORT: Listenning port
- HOST: Listenning host (Use localhost or public ip)

Exemples:

```bash
make serve PORT=3000
make serve HOST=10.122.36.54 PORT=3001
```