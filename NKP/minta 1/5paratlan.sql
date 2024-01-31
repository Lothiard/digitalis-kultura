SELECT csapat.nev
FROM csapat, meccs
WHERE csapat.id = meccs.ellenfel
GROUP BY 1
HAVING COUNT(*) % 2 = 1;