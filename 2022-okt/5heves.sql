SELECT COUNT(*)
FROM megye
WHERE megye.letszam <
    (SELECT megye.letszam
    FROM megye
    WHERE megye.nev = "Heves");