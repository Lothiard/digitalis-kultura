SELECT segito.nev
FROM ugyelet, segito
WHERE segito.id = ugyelet.segitoid
GROUP BY 1
ORDER BY COUNT(ugyelet.segitoid) DESC
LIMIT 1;