SELECT kezdes.kezdes
FROM
	(SELECT ugyelet.kezdes
	FROM ugyelet
    WHERE ugyelet.datum = "2020-01-01") AS kezdes,
    
    (SELECT ugyelet.kezdes, ugyelet.befejezes
    FROM ugyelet
    WHERE ugyelet.datum = "2020-01-01") AS befejezes
WHERE kezdes.kezdes BETWEEN befejezes.kezdes AND befejezes.befejezes
GROUP BY 1
ORDER BY COUNT(*) DESC
LIMIT 1;