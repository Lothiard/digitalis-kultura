SELECT DISTINCT segito.nev
FROM ugyelet, segito
WHERE segito.id = ugyelet.segitoid
AND ugyelet.datum = "2020-01-01"
AND "12:00:00" BETWEEN ugyelet.kezdes AND ugyelet.befejezes;