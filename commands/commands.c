#include <stdio.h>
#include "commands.h"
#include "add.h"

#include <string.h>

static void deploy(char *line);

void commands_manager(void) {
    char line[1024];

    while (1) {
        printf("> ");

        if (fgets(line,sizeof(line),stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = '\0';

        deploy(line);
    }
}

static void deploy(char *line) {
    char *prefix = strtok(line, " ");
    char *action = strtok(NULL, " ");

    if (prefix == NULL || action == NULL) {
        printf("Commande invalide. Exemple : /todo add pending Ma tâche\n");
        return;
    }

    if (strcmp(prefix, "/todo") != 0) {
        printf("Commande inconnue : %s\n", prefix);
        return;
    }

    if (strcmp(action, "add") == 0) {
        char *status = strtok(NULL, " ");

        if (status == NULL) {
            printf("Utilisation : /todo add <statut> <description>\n");
            return;
        }

        char *description = status + strlen(status) + 1;

        if (*description == '\0') {
            printf("Utilisation : /todo add <statut> <description>\n");
            return;
        }

        command_add(status, description);
    } else if (strcmp(action, "remove") == 0) {
        printf("La commande remove sera ajoutée plus tard.\n");
    } else if (strcmp(action, "list") == 0) {
        printf("La commande list sera ajoutée plus tard.\n");
    } else {
        printf("Commande inconnue : %s\n", action);
    }
}