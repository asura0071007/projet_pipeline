const express = require('express');
const app = express();
const port = 3000;

let scoreDomicile = 0;
let scoreExterieur = 0;

app.use(express.urlencoded({ extended: true }));

// Route principale : affiche l'interface graphique
app.get('/', (req, res) => {
    res.send(`
        <!DOCTYPE html>
        <html lang="fr">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>DevOps Esport Dashboard</title>
            <script src="https://cdn.tailwindcss.com"></script>
        </head>
        <body class="bg-gray-900 text-white font-sans flex flex-col items-center justify-center min-h-screen">
            <div class="bg-gray-800 p-8 rounded-2xl shadow-2xl w-full max-w-md text-center border border-gray-700">
                <h1 class="text-2xl font-black text-yellow-400 mb-2 tracking-wider">🏆 TOURNOI ESPORT 🏆</h1>
                <p class="text-gray-400 text-xs uppercase tracking-widest mb-6">Pipeline DevOps Monitoring</p>
                
                <div class="flex justify-between items-center bg-gray-900 p-6 rounded-xl my-4 border border-gray-700">
                    <div>
                        <p class="text-blue-400 font-bold text-sm uppercase tracking-wider">Domicile</p>
                        <p class="text-5xl font-black mt-2 text-white">${scoreDomicile}</p>
                    </div>
                    <div class="text-xl font-bold text-gray-600">VS</div>
                    <div>
                        <p class="text-red-400 font-bold text-sm uppercase tracking-wider">Extérieur</p>
                        <p class="text-5xl font-black mt-2 text-white">${scoreExterieur}</p>
                    </div>
                </div>

                <div class="grid grid-cols-2 gap-4 mt-6">
                    <form action="/but-domicile" method="POST">
                        <button type="submit" class="w-full bg-blue-600 hover:bg-blue-500 text-white font-bold py-3 px-4 rounded-xl transition duration-150 shadow-lg active:scale-95">⚽ But Domicile</button>
                    </form>
                    <form action="/but-exterieur" method="POST">
                        <button type="submit" class="w-full bg-red-600 hover:bg-red-500 text-white font-bold py-3 px-4 rounded-xl transition duration-150 shadow-lg active:scale-95">⚽ But Extérieur</button>
                    </form>
                </div>

                <form action="/reset" method="POST" class="mt-6">
                    <button type="submit" class="text-gray-500 hover:text-gray-300 text-xs underline tracking-wide transition">Réinitialiser le match</button>
                </form>
            </div>
            <p class="mt-6 text-gray-600 text-xs uppercase tracking-widest">Statut : Conteneur Stable • Port 3000</p>
        </body>
        </html>
    `);
});

// Routes pour gérer les actions et envoyer les logs/métriques pour Grafana
app.post('/but-domicile', (req, res) => {
    scoreDomicile++;
    console.log(`[METRIC] BUT_DOMICILE | Score actuel: ${scoreDomicile} - ${scoreExterieur}`);
    res.redirect('/');
});

app.post('/but-exterieur', (req, res) => {
    scoreExterieur++;
    console.log(`[METRIC] BUT_EXTERIEUR | Score actuel: ${scoreDomicile} - ${scoreExterieur}`);
    res.redirect('/');
});

app.post('/reset', (req, res) => {
    scoreDomicile = 0;
    scoreExterieur = 0;
    console.log(`[SYSTEME] Match réinitialisé.`);
    res.redirect('/');
});

app.listen(port, () => {
    console.log(`[SYSTEME] Application web démarrée avec succès sur http://localhost:${port}`);
});