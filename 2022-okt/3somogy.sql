SELECT SUM(aerob.letszam)
FROM megye, aerob
WHERE megye.kod = aerob.mkod
AND megye.nev = "Somogy";