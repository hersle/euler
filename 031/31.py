import time

GOAL = 200

time_start = time.time()
combos = 0
for a in range(0, int(GOAL / 1) + 1):
    sa = a
    for b in range(0, int((GOAL - sa) / 2) + 1):
        sb = sa + b * 2
        for c in range(0, int((GOAL - sb) / 5) + 1):
            sc = sb + c * 5
            for d in range(0, int((GOAL - sc) / 10) + 1):
                sd = sc + d * 10
                for e in range(0, int((GOAL - sd) / 20) + 1):
                    se = sd + e * 20
                    for f in range(0, int((GOAL - se) / 50) + 1):
                        sf = se + f * 50
                        for g in range(0, int((GOAL - sf) / 100) + 1):
                            sg = sf + g * 100
                            for h in range(0, int((GOAL - sg) / 200) + 1):
                                sh = sg + h * 200
                                if sh == GOAL:
                                    combos += 1
                                    print (a, b, c, d, e, f, g, h)

print ("Found %d combos in %f seconds" % (combos, time.time() - time_start))
