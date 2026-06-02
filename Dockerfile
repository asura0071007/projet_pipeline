# 1. Utiliser une image légère de Node.js
FROM node:18-alpine

# 2. Créer le dossier de travail dans le conteneur
WORKDIR /app

# 3. Copier les fichiers de configuration et installer les dépendances
COPY package*.json ./
RUN npm install

# 4. Copier le reste du code de l'application
COPY . .

# 5. Ouvrir le port 3000 pour pouvoir y accéder depuis le navigateur
EXPOSE 3000

# 6. Lancer l'application web
CMD ["npm", "start"]