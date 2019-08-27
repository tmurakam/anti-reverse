NAME = anti-reverse

all: image

image:
	docker build -t $(NAME) .

rmi:
	docker image rm $(NAME)

bash:
	docker container run -it --rm /bin/bash

start:
	docker container run -d $(NAME)
