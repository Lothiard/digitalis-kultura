SELECT DISTINCT csapat.nev
FROM csapat, meccs
WHERE csapat.id = meccs.ellenfel
AND meccs.datum BETWEEN "1995-09-01" AND "1995-11-30";