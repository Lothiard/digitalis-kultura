SELECT meccs.datum, IF(meccs.hazai = 1, "itthon", "idegenben") AS hol, ellenfel.nev, meccs.lott, meccs.kapott
FROM meccs, csapat AS magyar, csapat AS ellenfel
WHERE meccs.magyar = magyar.id
AND meccs.ellenfel = ellenfel.id
AND magyar.nev = "Videoton"
AND meccs.datum BETWEEN "1984-09-01" AND "1985-05-31"
ORDER BY 1;