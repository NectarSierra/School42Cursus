PATH_DOCKER_COMPOSE="./srcs/docker-compose.yml"
NAME=inception

all: up
$(NAME): up
re: down up
clean: down
fclean: destroy

up:
	@if [ -f ./secrets/db_password.txt -a -f ./secrets/db_root_password.txt -a -f ./secrets/certs/nginx.key -a -f ./secrets/certs/nginx.crt ]; then \
		sudo mkdir -p /home/${USER}/data; \
		sudo mkdir -p /home/${USER}/data/wordpress; \
		sudo mkdir -p /home/${USER}/data/mariadb; \
		sudo docker compose -f $(PATH_DOCKER_COMPOSE) up -d; \
	else \
		echo "\e[31mSecrets are missing - Operation Cancelled!\e[0m\nPlease follow the \e[33mREADME\e[0m file inside \e[33m./secrets\e[0m folder"; \
	fi
up_no_daemon:
	@if [ -f ./secrets/db_password.txt -a -f ./secrets/db_root_password.txt -a -f ./secrets/certs/nginx.key -a -f ./secrets/certs/nginx.crt ]; then \
		sudo mkdir -p /home/${USER}/data; \
		sudo mkdir -p /home/${USER}/data/wordpress; \
		sudo mkdir -p /home/${USER}/data/mariadb; \
		sudo docker compose -f $(PATH_DOCKER_COMPOSE) up; \
	else \
		echo "\e[31mSecrets are missing - Operation Cancelled!\e[0m\nPlease follow the \e[33mREADME\e[0m file inside \e[33m./secrets\e[0m folder"; \
	fi

stop:
	sudo docker compose -f $(PATH_DOCKER_COMPOSE) stop

down:
	sudo docker compose -f $(PATH_DOCKER_COMPOSE) down --rmi all

destroy:
	@echo -n "\e[31mThis will erase volumes\e[0m - Are you sure? [y/N] \e[0m" && read input && if [ $${input} = 'y' ]; then \
		sudo docker compose -f $(PATH_DOCKER_COMPOSE) down -v --rmi all;\
		sudo rm -rf /home/${USER}/data;\
	else \
		echo "Operation cancelled!"; \
	fi
