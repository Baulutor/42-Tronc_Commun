COMPOSE_FILE=srcs/docker-compose.yml

all:
	sudo mkdir -p /home/dbaule/data
	sudo mkdir -p /home/dbaule/data/wordpress
	sudo mkdir -p /home/dbaule/data/mariadb
	sudo docker compose -f $(COMPOSE_FILE) up --build -d

stop: 
	sudo docker compose -f $(COMPOSE_FILE) down

prune:
	sudo docker system prune -f --all --volumes

clean:
	sudo rm -rf /home/dbaule/data
	sudo docker compose -f $(COMPOSE_FILE) down --volumes --rmi all

fclean: 	
	sudo make stop
	sudo make clean
	sudo make prune

ps:
	sudo docker ps

lsi:
	sudo docker image ls

logsm:
	sudo docker compose -f $(COMPOSE_FILE) logs mariadb -f

logsw:
	sudo docker compose -f $(COMPOSE_FILE) logs wordpress -f

logsn:
	sudo docker compose -f $(COMPOSE_FILE) logs nginx -f

logs:
	sudo docker compose -f $(COMPOSE_FILE) logs -f

execm:
	sudo docker exec -it mariadb zsh

execw:
	sudo docker exec -it wordpress zsh

execn:
	sudo docker exec -it nginx zsh

re:
	sudo make clean
	sudo make all

.PHONY: all stop prune clean fclean ps lsi logsm logsw logsn logs execm execw execn re