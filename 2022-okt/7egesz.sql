SELECT megye.nev, aerob.letszam
FROM aerob, megye, allapot
WHERE aerob.mkod = megye.kod
AND allapot.kod = aerob.allkod
AND aerob.nem = 0
AND allapot.nev = "egészséges"
ORDER BY 2 DESC;