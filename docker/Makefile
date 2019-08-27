NAME = anti-reverse
DOCKER = docker
#DOCKER = podman

all: image

image:
	$(DOCKER) build -t $(NAME) .

rmi:
	$(DOCKER) image rm $(NAME)

bash:
	$(DOCKER) container run -it --rm $(NAME) /bin/bash

start:
	$(DOCKER) container run -d $(NAME)
