SELECT segito.nev, segito.telefonszam
FROM segito
WHERE segito.telefonszam IS NOT NULL
AND segito.szakember = 1
ORDER BY segito.nev;
