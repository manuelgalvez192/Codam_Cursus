#variables
COMPOSE_FILE = srcs/docker-compose.yml
DATA_DIR = /home/$(USER)/data

.PHONY: all build up down clean fclean re

all: build up

#create data directories
$(DATA_DIR)/mariadb:
	mkdir -p $(DATA_DIR)/mariadb

$(DATA_DIR)/wordpress:
	mkdir -p $(DATA_DIR)/wordpress

#build images
build: $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
	docker compose -f $(COMPOSE_FILE) build

#start services
up:
	docker compose -f $(COMPOSE_FILE) up -d

#stop services
down:
	docker compose -f $(COMPOSE_FILE) down

#clean containers and images
clean:
	docker compose -f $(COMPOSE_FILE) down
	docker system prune -af

#full clean including volumes
fclean: clean
	docker volume prune -f
	sudo rm -rf $(DATA_DIR)

#rebuild everything
re: fclean all