SELECT aerob.letszam
FROM megye, aerob, allapot
WHERE megye.kod = aerob.mkod
AND aerob.allkod = allapot.kod
AND megye.nev = "Zala"
AND aerob.nem = 1
AND allapot.nev = "egészséges";