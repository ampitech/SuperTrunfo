import os

# Define a estrutura de diretórios e arquivos
structure = {
    "super_trunfo_futebol": {
        "src": {
            "main.c": "",
            "carta.c": "",
            "baralho.c": "",
            "jogo.c": ""
        },
        "include": {
            "carta.h": "",
            "baralho.h": "",
            "jogo.h": ""
        },
        "Makefile": "",
        "README.md": "",
        ".gitignore": ""
    }
}

# Função para criar a estrutura de diretórios e arquivos
def create_structure(base_path, structure):
    for key, value in structure.items():
        path = os.path.join(base_path, key)
        if isinstance(value, dict):
            os.makedirs(path, exist_ok=True)
            create_structure(path, value)
        else:
            with open(path, 'w') as f:
                f.write(value)

# Cria a estrutura a partir do diretório atual
create_structure(os.getcwd(), structure)

print("Estrutura de diretórios e arquivos criada com sucesso!")