SELECT megye.nev AS Megyenév, SUM(aerob.letszam) / megye.letszam AS Arány
FROM megye, aerob, allapot
WHERE megye.kod = aerob.mkod
AND allapot.kod = aerob.allkod
AND allapot.nev LIKE "%fejlesztést igényel"
GROUP BY 1
HAVING Arány > 1 / 4;