SELECT segito.nev
FROM segito, ugyelet
WHERE ugyelet.segitoid = segito.id
AND ugyelet.datum = "2021-12-24"
AND segito.nev IN
    (SELECT segito.nev
    FROM segito, ugyelet
    WHERE ugyelet.segitoid = segito.id
    AND ugyelet.datum = "2020-12-24");