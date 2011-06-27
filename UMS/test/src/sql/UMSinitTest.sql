INSERT INTO vishnu (vishnuid, updatefreq, formatiduser, formatidmachine, formatidjob, formatidfiletransfer, usercpt, machinecpt, jobcpt, filesubcpt) VALUES (1, 0, 'U_$CPT', 'MA_$CPT', 'J_$CPT', 'FT_$CPT', 1, 1, 1, 1);
INSERT INTO optionu (optionid, description, defaultvalue) VALUES (1, 'VISHNU_CLOSE_POLICY', 1);
INSERT INTO optionu (optionid, description, defaultvalue) VALUES (2, 'VISHNU_TIMEOUT', 3600);
INSERT INTO users(vishnu_vishnuid, userid, pwd, privilege, passwordstate, status)VALUES(1, 'root','8vU7h/n6KOW8reLF1Lt2/5gzjZ.HvGK3A9doVMbmPtaYKkkCoWrMKiPa7s.fEigSTS5gQmX5F8BlW2XotCeHa0', 1, 1, 1);
INSERT INTO users(vishnu_vishnuid, userid, pwd, firstname, lastname, privilege, email, passwordstate, status) values(1, 'admin_1', '75fvsW7kKijHx.KbF4V5PapqRw6SZcUVNOMawX1dbwoktJS1xvjZPZLwPVtrI2KG0a1lOnTeZlwyfuVMDr4Ay0', 'jean', 'dupont', 1, 'admin@admin.com', 1, 1);
INSERT INTO users(vishnu_vishnuid, userid, pwd, firstname, lastname, privilege, email, passwordstate, status) values(1, 'user_1', 'r0Mk0M4TsQKJE3lhP.yll0fKJgNKbWaAVo5MUuJtRRhQQot6AnOHXWhm1Mra92pgkD6zGRHmS78J/mIsw5mMA1', 'jeannot', 'dupont', 0, 'user@user.com', 1, 1);
UPDATE users SET numuserid=1 where userid='root';
UPDATE users SET numuserid=2 where userid='admin_1';
UPDATE users SET numuserid=3 where userid='user_1';
INSERT INTO machine(vishnu_vishnuid, name, site, machineid, status)values(1, '@TEST_LOCAL_HOSTNAME@', 'berlin', 'machine_1', '1');
INSERT INTO machine(vishnu_vishnuid, name, site, machineid, status)values(1, 'tiger2', 'paris', 'machine_42', '1');
UPDATE machine SET nummachineid=1 where machineid='machine_1';
UPDATE machine SET nummachineid=2 where machineid='machine_42';
INSERT INTO description(machine_nummachineid, lang, description) values(1, 'ang', 'nutella');
UPDATE description SET numdescriptionid=1 where description='nutella';
INSERT INTO description(machine_nummachineid, lang, description) values(2, 'ang', 'chocolate');
UPDATE description SET numdescriptionid=2 where description='chocolate';

