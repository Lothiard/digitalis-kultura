SELECT SUM(aerob.letszam) / megye.letszam
FROM megye, aerob
WHERE megye.kod = aerob.mkod
AND megye.nev = "Pest";