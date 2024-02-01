SELECT segito.nev
FROM segito
WHERE segito.nev NOT IN
    (SELECT segito.nev
    FROM segito, ugyelet
    WHERE ugyelet.segitoid = segito.id
    AND MONTH(ugyelet.datum) = 12);