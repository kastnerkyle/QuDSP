#ifndef _WINDOW_H_
#define _WINDOW_H_
#define WINDOWLEN 2048
static const float window[WINDOWLEN] = {
7e-05,
7.01332714001e-05,
7.05331222657e-05,
7.11996625927e-05,
7.2133075708e-05,
7.3333618269e-05,
7.48016202632e-05,
7.65374850087e-05,
7.85416891538e-05,
8.08147826765e-05,
8.33573888843e-05,
8.61702044145e-05,
8.92539992328e-05,
9.26096166339e-05,
9.62379732401e-05,
0.000100140059002,
0.000104316937196,
0.000108769744427,
0.000113499690623,
0.000118508059038,
0.000123796206252,
0.000129365562164,
0.000135217629998,
0.000141353986299,
0.00014777628093,
0.000154486237074,
0.000161485651229,
0.00016877639321,
0.000176360406146,
0.000184239706475,
0.000192416383947,
0.00020089260162,
0.000209670595855,
0.000218752676317,
0.000228141225971,
0.000237838701079,
0.000247847631197,
0.000258170619172,
0.000268810341137,
0.000279769546509,
0.000291051057985,
0.000302657771537,
0.000314592656405,
0.000326858755099,
0.000339459183385,
0.000352397130287,
0.000365675858076,
0.000379298702269,
0.000393269071616,
0.000407590448099,
0.000422266386923,
0.000437300516505,
0.000452696538471,
0.000468458227646,
0.000484589432043,
0.000501094072855,
0.000517976144447,
0.000535239714341,
0.000552888923211,
0.000570927984867,
0.000589361186245,
0.000608192887396,
0.00062742752147,
0.000647069594704,
0.000667123686408,
0.000687594448949,
0.000708486607736,
0.000729804961205,
0.000751554380802,
0.000773739810963,
0.000796366269098,
0.000819438845571,
0.000842962703681,
0.000866943079641,
0.000891385282558,
0.000916294694407,
0.000941676770012,
0.000967537037019,
0.000993881095876,
0.0010207146198,
0.00104804335476,
0.00107587311944,
0.00110420980521,
0.0011330593761,
0.00116242786879,
0.00119232139254,
0.00122274612918,
0.00125370833306,
0.00128521433106,
0.00131727052248,
0.00134988337907,
0.00138305944497,
0.00141680533665,
0.00145112774288,
0.00148603342472,
0.00152152921544,
0.00155762202045,
0.00159431881735,
0.00163162665577,
0.00166955265741,
0.00170810401592,
0.00174728799692,
0.00178711193786,
0.00182758324806,
0.00186870940858,
0.00191049797221,
0.00195295656337,
0.00199609287809,
0.00203991468391,
0.00208442981986,
0.00212964619633,
0.00217557179509,
0.00222221466913,
0.00226958294266,
0.002317684811,
0.0023665285405,
0.00241612246851,
0.00246647500324,
0.00251759462373,
0.00256948987974,
0.00262216939169,
0.00267564185053,
0.00272991601772,
0.00278500072507,
0.00284090487469,
0.0028976374389,
0.0029552074601,
0.0030136240507,
0.00307289639303,
0.00313303373919,
0.00319404541099,
0.00325594079984,
0.0033187293666,
0.00338242064152,
0.00344702422409,
0.00351254978296,
0.00357900705577,
0.00364640584907,
0.0037147560382,
0.00378406756712,
0.00385435044832,
0.0039256147627,
0.00399787065938,
0.00407112835563,
0.00414539813669,
0.00422069035563,
0.00429701543323,
0.00437438385781,
0.00445280618509,
0.00453229303805,
0.00461285510673,
0.00469450314814,
0.00477724798605,
0.00486110051083,
0.00494607167932,
0.00503217251459,
0.00511941410586,
0.00520780760825,
0.00529736424264,
0.00538809529546,
0.00548001211855,
0.00557312612892,
0.0056674488086,
0.00576299170443,
0.00585976642785,
0.00595778465473,
0.00605705812515,
0.00615759864319,
0.00625941807672,
0.0063625283572,
0.00646694147945,
0.00657266950144,
0.00667972454404,
0.00678811879085,
0.00689786448792,
0.00700897394352,
0.00712145952792,
0.00723533367315,
0.00735060887275,
0.00746729768152,
0.00758541271527,
0.00770496665056,
0.00782597222445,
0.00794844223425,
0.00807238953722,
0.00819782705033,
0.00832476774997,
0.00845322467169,
0.00858321090989,
0.00871473961758,
0.00884782400604,
0.00898247734457,
0.00911871296017,
0.00925654423725,
0.00939598461731,
0.00953704759866,
0.00967974673608,
0.00982409564054,
0.00997010797882,
0.0101177974733,
0.0102671779014,
0.0104182630955,
0.0105710669426,
0.0107256033838,
0.0108818864139,
0.0110399300815,
0.011199748488,
0.0113613557878,
0.0115247661877,
0.0116899939465,
0.0118570533747,
0.0120259588342,
0.0121967247377,
0.0123693655486,
0.0125438957802,
0.0127203299958,
0.0128986828081,
0.0130789688788,
0.0132612029178,
0.0134453996837,
0.0136315739824,
0.0138197406675,
0.0140099146393,
0.0142021108445,
0.0143963442761,
0.0145926299727,
0.0147909830177,
0.0149914185398,
0.0151939517116,
0.0153985977495,
0.0156053719137,
0.0158142895067,
0.016025365874,
0.0162386164028,
0.0164540565217,
0.0166717017006,
0.0168915674497,
0.0171136693193,
0.0173380228993,
0.0175646438187,
0.0177935477448,
0.0180247503831,
0.0182582674767,
0.0184941148054,
0.0187323081859,
0.0189728634704,
0.0192157965469,
0.0194611233381,
0.019708859801,
0.0199590219264,
0.0202116257385,
0.020466687294,
0.0207242226818,
0.0209842480223,
0.021246779467,
0.0215118331977,
0.0217794254262,
0.0220495723932,
0.0223222903686,
0.0225975956498,
0.022875504562,
0.0231560334572,
0.0234391987136,
0.0237250167352,
0.0240135039507,
0.0243046768137,
0.024598551801,
0.024895145413,
0.0251944741724,
0.0254965546239,
0.0258014033331,
0.0261090368866,
0.0264194718906,
0.0267327249706,
0.027048812771,
0.0273677519536,
0.0276895591978,
0.0280142511996,
0.0283418446706,
0.0286723563378,
0.0290058029427,
0.0293422012405,
0.0296815679997,
0.0300239200008,
0.0303692740364,
0.0307176469099,
0.031069055435,
0.0314235164347,
0.0317810467411,
0.0321416631941,
0.0325053826411,
0.032872221936,
0.0332421979385,
0.0336153275133,
0.0339916275297,
0.0343711148603,
0.0347538063805,
0.0351397189678,
0.0355288695009,
0.0359212748589,
0.0363169519207,
0.0367159175641,
0.0371181886648,
0.0375237820961,
0.0379327147274,
0.0383450034242,
0.0387606650467,
0.0391797164491,
0.0396021744789,
0.0400280559761,
0.0404573777723,
0.0408901566898,
0.0413264095408,
0.0417661531267,
0.042209404237,
0.0426561796489,
0.0431064961259,
0.0435603704171,
0.0440178192568,
0.0444788593631,
0.044943507437,
0.045411780162,
0.0458836942029,
0.046359266205,
0.0468385127931,
0.0473214505707,
0.0478080961194,
0.0482984659974,
0.048792576739,
0.0492904448538,
0.0497920868255,
0.050297519111,
0.0508067581399,
0.0513198203129,
0.0518367220016,
0.0523574795472,
0.0528821092593,
0.0534106274157,
0.0539430502608,
0.0544793940051,
0.0550196748238,
0.0555639088565,
0.0561121122055,
0.0566643009355,
0.0572204910724,
0.0577806986022,
0.0583449394702,
0.05891322958,
0.0594855847926,
0.0600620209255,
0.0606425537512,
0.0612271989971,
0.0618159723438,
0.0624088894244,
0.0630059658236,
0.0636072170764,
0.0642126586676,
0.0648223060303,
0.0654361745453,
0.0660542795399,
0.066676636287,
0.0673032600038,
0.0679341658515,
0.0685693689333,
0.0692088842945,
0.0698527269205,
0.0705009117364,
0.0711534536058,
0.0718103673297,
0.0724716676458,
0.073137369227,
0.0738074866807,
0.0744820345478,
0.0751610273015,
0.0758444793464,
0.0765324050174,
0.0772248185787,
0.0779217342228,
0.0786231660694,
0.0793291281645,
0.0800396344791,
0.0807546989085,
0.0814743352709,
0.0821985573067,
0.0829273786772,
0.0836608129638,
0.0843988736666,
0.0851415742039,
0.0858889279106,
0.0866409480373,
0.0873976477496,
0.0881590401266,
0.0889251381601,
0.0896959547534,
0.0904715027205,
0.0912517947848,
0.0920368435781,
0.0928266616397,
0.093621261415,
0.0944206552549,
0.0952248554145,
0.0960338740519,
0.0968477232276,
0.0976664149028,
0.0984899609391,
0.0993183730966,
0.100151663034,
0.100989842306,
0.101832922363,
0.102680914552,
0.103533830112,
0.104391680174,
0.105254475762,
0.10612222779,
0.106994947062,
0.10787264427,
0.108755329993,
0.109643014696,
0.110535708732,
0.111433422334,
0.112336165622,
0.113243948596,
0.114156781138,
0.115074673009,
0.115997633851,
0.116925673181,
0.117858800396,
0.118797024767,
0.11974035544,
0.120688801437,
0.121642371649,
0.122601074842,
0.123564919652,
0.124533914583,
0.12550806801,
0.126487388174,
0.127471883183,
0.128461561013,
0.1294564295,
0.130456496347,
0.131461769119,
0.132472255243,
0.133487962004,
0.13450889655,
0.135535065885,
0.136566476872,
0.13760313623,
0.138645050534,
0.139692226212,
0.140744669548,
0.141802386678,
0.142865383587,
0.143933666115,
0.145007239947,
0.146086110621,
0.14717028352,
0.148259763875,
0.149354556761,
0.150454667101,
0.15156009966,
0.152670859044,
0.153786949706,
0.154908375934,
0.156035141862,
0.157167251458,
0.158304708533,
0.159447516731,
0.160595679535,
0.161749200263,
0.162908082068,
0.164072327935,
0.165241940683,
0.166416922963,
0.167597277257,
0.168783005877,
0.169974110962,
0.171170594483,
0.172372458237,
0.173579703845,
0.174792332759,
0.17601034625,
0.177233745417,
0.17846253118,
0.179696704284,
0.180936265292,
0.18218121459,
0.183431552382,
0.184687278693,
0.185948393365,
0.187214896057,
0.188486786246,
0.189764063223,
0.191046726094,
0.192334773782,
0.193628205019,
0.194927018353,
0.196231212143,
0.197540784558,
0.198855733579,
0.200176056994,
0.201501752404,
0.202832817213,
0.204169248637,
0.205511043696,
0.206858199217,
0.208210711831,
0.209568577975,
0.210931793888,
0.212300355615,
0.213674259002,
0.215053499695,
0.216438073143,
0.217827974596,
0.219223199104,
0.220623741513,
0.222029596471,
0.223440758423,
0.224857221611,
0.226278980072,
0.227706027644,
0.229138357954,
0.23057596443,
0.23201884029,
0.233466978548,
0.234920372009,
0.236379013274,
0.237842894734,
0.239312008571,
0.240786346759,
0.242265901062,
0.243750663036,
0.245240624022,
0.246735775155,
0.248236107356,
0.249741611333,
0.251252277584,
0.252768096393,
0.254289057829,
0.255815151751,
0.257346367799,
0.258882695403,
0.260424123775,
0.261970641912,
0.263522238595,
0.26507890239,
0.266640621645,
0.268207384491,
0.269779178843,
0.271355992396,
0.27293781263,
0.274524626803,
0.276116421958,
0.277713184915,
0.279314902278,
0.280921560429,
0.282533145532,
0.28414964353,
0.285771040146,
0.28739732088,
0.289028471014,
0.290664475608,
0.2923053195,
0.293950987306,
0.295601463421,
0.297256732019,
0.298916777049,
0.30058158224,
0.302251131099,
0.303925406906,
0.305604392724,
0.30728807139,
0.308976425517,
0.310669437496,
0.312367089497,
0.314069363462,
0.315776241113,
0.317487703948,
0.319203733241,
0.320924310042,
0.322649415177,
0.32437902925,
0.326113132641,
0.327851705505,
0.329594727775,
0.331342179158,
0.333094039141,
0.334850286984,
0.336610901725,
0.33837586218,
0.340145146938,
0.341918734368,
0.343696602616,
0.345478729601,
0.347265093024,
0.34905567036,
0.350850438863,
0.352649375564,
0.35445245727,
0.35625966057,
0.358070961826,
0.359886337182,
0.36170576256,
0.363529213658,
0.365356665957,
0.367188094713,
0.369023474966,
0.37086278153,
0.372705989005,
0.374553071768,
0.376404003976,
0.378258759568,
0.380117312266,
0.381979635571,
0.383845702767,
0.385715486919,
0.387588960878,
0.389466097274,
0.391346868524,
0.393231246826,
0.395119204165,
0.397010712308,
0.39890574281,
0.400804267009,
0.402706256031,
0.404611680788,
0.40652051198,
0.408432720092,
0.4103482754,
0.412267147968,
0.414189307647,
0.416114724082,
0.418043366704,
0.419975204737,
0.421910207198,
0.423848342892,
0.42578958042,
0.427733888176,
0.429681234347,
0.431631586915,
0.433584913657,
0.435541182147,
0.437500359755,
0.439462413647,
0.44142731079,
0.443395017946,
0.44536550168,
0.447338728356,
0.449314664138,
0.451293274993,
0.453274526689,
0.4552583848,
0.457244814702,
0.459233781576,
0.461225250409,
0.463219185996,
0.465215552938,
0.467214315643,
0.469215438331,
0.471218885032,
0.473224619583,
0.475232605638,
0.47724280666,
0.479255185929,
0.481269706535,
0.483286331388,
0.485305023213,
0.487325744553,
0.489348457767,
0.491373125037,
0.493399708363,
0.495428169569,
0.497458470299,
0.499490572023,
0.501524436032,
0.503560023447,
0.505597295214,
0.507636212106,
0.509676734727,
0.511718823508,
0.513762438715,
0.515807540443,
0.517854088623,
0.51990204302,
0.521951363233,
0.5240020087,
0.526053938697,
0.528107112339,
0.53016148858,
0.532217026219,
0.534273683895,
0.536331420093,
0.538390193142,
0.54044996122,
0.542510682351,
0.54457231441,
0.546634815119,
0.548698142057,
0.550762252653,
0.55282710419,
0.554892653809,
0.556958858506,
0.559025675138,
0.56109306042,
0.563160970928,
0.565229363102,
0.567298193245,
0.569367417526,
0.571436991981,
0.573506872513,
0.575577014896,
0.577647374775,
0.579717907667,
0.581788568962,
0.583859313927,
0.585930097707,
0.588000875322,
0.590071601675,
0.592142231549,
0.59421271961,
0.596283020409,
0.598353088382,
0.600422877854,
0.602492343037,
0.604561438036,
0.606630116846,
0.608698333357,
0.610766041354,
0.612833194518,
0.614899746431,
0.616965650572,
0.619030860324,
0.621095328972,
0.623159009706,
0.625221855625,
0.627283819732,
0.629344854943,
0.631404914086,
0.633463949899,
0.635521915038,
0.637578762073,
0.639634443496,
0.641688911715,
0.643742119062,
0.645794017791,
0.647844560082,
0.649893698041,
0.651941383705,
0.653987569037,
0.656032205937,
0.658075246234,
0.660116641696,
0.662156344026,
0.664194304869,
0.666230475807,
0.668264808368,
0.670297254023,
0.672327764188,
0.674356290231,
0.676382783464,
0.678407195157,
0.680429476528,
0.682449578754,
0.684467452966,
0.686483050258,
0.688496321682,
0.690507218252,
0.692515690949,
0.694521690718,
0.696525168474,
0.698526075102,
0.700524361457,
0.702519978371,
0.704512876648,
0.706503007072,
0.708490320407,
0.710474767398,
0.712456298771,
0.714434865239,
0.716410417504,
0.718382906254,
0.720352282168,
0.722318495921,
0.724281498179,
0.726241239606,
0.728197670867,
0.730150742624,
0.732100405544,
0.734046610297,
0.735989307559,
0.737928448017,
0.739863982365,
0.741795861311,
0.743724035577,
0.745648455901,
0.74756907304,
0.749485837768,
0.751398700885,
0.753307613213,
0.755212525599,
0.75711338892,
0.759010154082,
0.760902772021,
0.762791193711,
0.764675370158,
0.766555252407,
0.768430791544,
0.770301938695,
0.77216864503,
0.774030861766,
0.775888540166,
0.777741631544,
0.779590087266,
0.781433858749,
0.783272897469,
0.785107154957,
0.786936582805,
0.788761132666,
0.790580756258,
0.792395405361,
0.794205031828,
0.796009587576,
0.797809024597,
0.799603294955,
0.80139235079,
0.80317614432,
0.804954627842,
0.806727753733,
0.808495474456,
0.810257742557,
0.812014510672,
0.813765731524,
0.815511357927,
0.817251342792,
0.818985639121,
0.820714200015,
0.822436978675,
0.824153928402,
0.8258650026,
0.827570154779,
0.829269338556,
0.830962507657,
0.832649615917,
0.834330617288,
0.836005465832,
0.837674115732,
0.839336521288,
0.84099263692,
0.842642417172,
0.844285816712,
0.845922790335,
0.847553292963,
0.84917727965,
0.850794705581,
0.852405526076,
0.854009696592,
0.855607172722,
0.8571979102,
0.858781864902,
0.860358992847,
0.861929250201,
0.863492593275,
0.865048978532,
0.866598362586,
0.868140702202,
0.869675954301,
0.871204075962,
0.872725024422,
0.874238757079,
0.875745231492,
0.877244405384,
0.878736236648,
0.88022068334,
0.881697703689,
0.883167256094,
0.884629299127,
0.886083791538,
0.88753069225,
0.888969960368,
0.890401555176,
0.891825436141,
0.893241562913,
0.894649895329,
0.896050393413,
0.897443017379,
0.898827727632,
0.900204484769,
0.901573249583,
0.902933983061,
0.904286646392,
0.905631200961,
0.906967608356,
0.908295830368,
0.909615828993,
0.910927566434,
0.9122310051,
0.913526107612,
0.914812836802,
0.916091155716,
0.917361027612,
0.918622415967,
0.919875284475,
0.921119597051,
0.922355317829,
0.923582411167,
0.924800841647,
0.926010574079,
0.927211573497,
0.928403805167,
0.929587234584,
0.930761827477,
0.931927549807,
0.933084367772,
0.934232247803,
0.935371156575,
0.936501060997,
0.937621928224,
0.938733725651,
0.939836420917,
0.940929981908,
0.942014376757,
0.943089573844,
0.9441555418,
0.945212249507,
0.9462596661,
0.947297760969,
0.948326503757,
0.949345864366,
0.950355812954,
0.951356319942,
0.952347356009,
0.953328892097,
0.954300899411,
0.955263349422,
0.956216213866,
0.957159464747,
0.958093074338,
0.959017015179,
0.959931260086,
0.960835782144,
0.961730554711,
0.962615551423,
0.963490746188,
0.964356113194,
0.965211626908,
0.966057262072,
0.966892993714,
0.96771879714,
0.968534647941,
0.969340521991,
0.970136395448,
0.97092224476,
0.971698046657,
0.972463778161,
0.973219416582,
0.973964939521,
0.97470032487,
0.975425550813,
0.976140595827,
0.976845438686,
0.977540058456,
0.978224434501,
0.978898546482,
0.979562374358,
0.980215898387,
0.980859099128,
0.981491957439,
0.982114454481,
0.982726571717,
0.983328290914,
0.983919594143,
0.98450046378,
0.985070882507,
0.985630833313,
0.986180299492,
0.986719264651,
0.987247712702,
0.987765627868,
0.988272994683,
0.988769797991,
0.989256022948,
0.989731655024,
0.99019668,
0.990651083972,
0.991094853352,
0.991527974863,
0.991950435548,
0.992362222763,
0.992763324184,
0.993153727802,
0.993533421926,
0.993902395185,
0.994260636527,
0.994608135217,
0.994944880844,
0.995270863314,
0.995586072857,
0.995890500021,
0.996184135679,
0.996466971024,
0.996738997574,
0.997000207168,
0.997250591969,
0.997490144465,
0.997718857467,
0.997936724111,
0.998143737856,
0.99833989249,
0.998525182123,
0.998699601191,
0.998863144457,
0.999015807011,
0.999157584268,
0.999288471968,
0.999408466182,
0.999517563304,
0.999615760057,
0.999703053492,
0.999779440985,
0.999844920242,
0.999899489296,
0.999943146506,
0.999975890562,
0.999997720479,
1.0000086356,
1.0000086356,
0.999997720479,
0.999975890562,
0.999943146506,
0.999899489296,
0.999844920242,
0.999779440985,
0.999703053492,
0.999615760057,
0.999517563304,
0.999408466182,
0.999288471968,
0.999157584268,
0.999015807011,
0.998863144457,
0.998699601191,
0.998525182123,
0.99833989249,
0.998143737856,
0.997936724111,
0.997718857467,
0.997490144465,
0.997250591969,
0.997000207168,
0.996738997574,
0.996466971024,
0.996184135679,
0.995890500021,
0.995586072857,
0.995270863314,
0.994944880844,
0.994608135217,
0.994260636527,
0.993902395185,
0.993533421926,
0.993153727802,
0.992763324184,
0.992362222763,
0.991950435548,
0.991527974863,
0.991094853352,
0.990651083972,
0.99019668,
0.989731655024,
0.989256022948,
0.988769797991,
0.988272994683,
0.987765627868,
0.987247712702,
0.986719264651,
0.986180299492,
0.985630833313,
0.985070882507,
0.98450046378,
0.983919594143,
0.983328290914,
0.982726571717,
0.982114454481,
0.981491957439,
0.980859099128,
0.980215898387,
0.979562374358,
0.978898546482,
0.978224434501,
0.977540058456,
0.976845438686,
0.976140595827,
0.975425550813,
0.97470032487,
0.973964939521,
0.973219416582,
0.972463778161,
0.971698046657,
0.97092224476,
0.970136395448,
0.969340521991,
0.968534647941,
0.96771879714,
0.966892993714,
0.966057262072,
0.965211626908,
0.964356113194,
0.963490746188,
0.962615551423,
0.961730554711,
0.960835782144,
0.959931260086,
0.959017015179,
0.958093074338,
0.957159464747,
0.956216213866,
0.955263349422,
0.954300899411,
0.953328892097,
0.952347356009,
0.951356319942,
0.950355812954,
0.949345864366,
0.948326503757,
0.947297760969,
0.9462596661,
0.945212249507,
0.9441555418,
0.943089573844,
0.942014376757,
0.940929981908,
0.939836420917,
0.938733725651,
0.937621928224,
0.936501060997,
0.935371156575,
0.934232247803,
0.933084367772,
0.931927549807,
0.930761827477,
0.929587234584,
0.928403805167,
0.927211573497,
0.926010574079,
0.924800841647,
0.923582411167,
0.922355317829,
0.921119597051,
0.919875284475,
0.918622415967,
0.917361027612,
0.916091155716,
0.914812836802,
0.913526107612,
0.9122310051,
0.910927566434,
0.909615828993,
0.908295830368,
0.906967608356,
0.905631200961,
0.904286646392,
0.902933983061,
0.901573249583,
0.900204484769,
0.898827727632,
0.897443017379,
0.896050393413,
0.894649895329,
0.893241562913,
0.891825436141,
0.890401555176,
0.888969960368,
0.88753069225,
0.886083791538,
0.884629299127,
0.883167256094,
0.881697703689,
0.88022068334,
0.878736236648,
0.877244405384,
0.875745231492,
0.874238757079,
0.872725024422,
0.871204075962,
0.869675954301,
0.868140702202,
0.866598362586,
0.865048978532,
0.863492593275,
0.861929250201,
0.860358992847,
0.858781864902,
0.8571979102,
0.855607172722,
0.854009696592,
0.852405526076,
0.850794705581,
0.84917727965,
0.847553292963,
0.845922790335,
0.844285816712,
0.842642417172,
0.84099263692,
0.839336521288,
0.837674115732,
0.836005465832,
0.834330617288,
0.832649615917,
0.830962507657,
0.829269338556,
0.827570154779,
0.8258650026,
0.824153928402,
0.822436978675,
0.820714200015,
0.818985639121,
0.817251342792,
0.815511357927,
0.813765731524,
0.812014510672,
0.810257742557,
0.808495474456,
0.806727753733,
0.804954627842,
0.80317614432,
0.80139235079,
0.799603294955,
0.797809024597,
0.796009587576,
0.794205031828,
0.792395405361,
0.790580756258,
0.788761132666,
0.786936582805,
0.785107154957,
0.783272897469,
0.781433858749,
0.779590087266,
0.777741631544,
0.775888540166,
0.774030861766,
0.77216864503,
0.770301938695,
0.768430791544,
0.766555252407,
0.764675370158,
0.762791193711,
0.760902772021,
0.759010154082,
0.75711338892,
0.755212525599,
0.753307613213,
0.751398700885,
0.749485837768,
0.74756907304,
0.745648455901,
0.743724035577,
0.741795861311,
0.739863982365,
0.737928448017,
0.735989307559,
0.734046610297,
0.732100405544,
0.730150742624,
0.728197670867,
0.726241239606,
0.724281498179,
0.722318495921,
0.720352282168,
0.718382906254,
0.716410417504,
0.714434865239,
0.712456298771,
0.710474767398,
0.708490320407,
0.706503007072,
0.704512876648,
0.702519978371,
0.700524361457,
0.698526075102,
0.696525168474,
0.694521690718,
0.692515690949,
0.690507218252,
0.688496321682,
0.686483050258,
0.684467452966,
0.682449578754,
0.680429476528,
0.678407195157,
0.676382783464,
0.674356290231,
0.672327764188,
0.670297254023,
0.668264808368,
0.666230475807,
0.664194304869,
0.662156344026,
0.660116641696,
0.658075246234,
0.656032205937,
0.653987569037,
0.651941383705,
0.649893698041,
0.647844560082,
0.645794017791,
0.643742119062,
0.641688911715,
0.639634443496,
0.637578762073,
0.635521915038,
0.633463949899,
0.631404914086,
0.629344854943,
0.627283819732,
0.625221855625,
0.623159009706,
0.621095328972,
0.619030860324,
0.616965650572,
0.614899746431,
0.612833194518,
0.610766041354,
0.608698333357,
0.606630116846,
0.604561438036,
0.602492343037,
0.600422877854,
0.598353088382,
0.596283020409,
0.59421271961,
0.592142231549,
0.590071601675,
0.588000875322,
0.585930097707,
0.583859313927,
0.581788568962,
0.579717907667,
0.577647374775,
0.575577014896,
0.573506872513,
0.571436991981,
0.569367417526,
0.567298193245,
0.565229363102,
0.563160970928,
0.56109306042,
0.559025675138,
0.556958858506,
0.554892653809,
0.55282710419,
0.550762252653,
0.548698142057,
0.546634815119,
0.54457231441,
0.542510682351,
0.54044996122,
0.538390193142,
0.536331420093,
0.534273683895,
0.532217026219,
0.53016148858,
0.528107112339,
0.526053938697,
0.5240020087,
0.521951363233,
0.51990204302,
0.517854088623,
0.515807540443,
0.513762438715,
0.511718823508,
0.509676734727,
0.507636212106,
0.505597295214,
0.503560023447,
0.501524436032,
0.499490572023,
0.497458470299,
0.495428169569,
0.493399708363,
0.491373125037,
0.489348457767,
0.487325744553,
0.485305023213,
0.483286331388,
0.481269706535,
0.479255185929,
0.47724280666,
0.475232605638,
0.473224619583,
0.471218885032,
0.469215438331,
0.467214315643,
0.465215552938,
0.463219185996,
0.461225250409,
0.459233781576,
0.457244814702,
0.4552583848,
0.453274526689,
0.451293274993,
0.449314664138,
0.447338728356,
0.44536550168,
0.443395017946,
0.44142731079,
0.439462413647,
0.437500359755,
0.435541182147,
0.433584913657,
0.431631586915,
0.429681234347,
0.427733888176,
0.42578958042,
0.423848342892,
0.421910207198,
0.419975204737,
0.418043366704,
0.416114724082,
0.414189307647,
0.412267147968,
0.4103482754,
0.408432720092,
0.40652051198,
0.404611680788,
0.402706256031,
0.400804267009,
0.39890574281,
0.397010712308,
0.395119204165,
0.393231246826,
0.391346868524,
0.389466097274,
0.387588960878,
0.385715486919,
0.383845702767,
0.381979635571,
0.380117312266,
0.378258759568,
0.376404003976,
0.374553071768,
0.372705989005,
0.37086278153,
0.369023474966,
0.367188094713,
0.365356665957,
0.363529213658,
0.36170576256,
0.359886337182,
0.358070961826,
0.35625966057,
0.35445245727,
0.352649375564,
0.350850438863,
0.34905567036,
0.347265093024,
0.345478729601,
0.343696602616,
0.341918734368,
0.340145146938,
0.33837586218,
0.336610901725,
0.334850286984,
0.333094039141,
0.331342179158,
0.329594727775,
0.327851705505,
0.326113132641,
0.32437902925,
0.322649415177,
0.320924310042,
0.319203733241,
0.317487703948,
0.315776241113,
0.314069363462,
0.312367089497,
0.310669437496,
0.308976425517,
0.30728807139,
0.305604392724,
0.303925406906,
0.302251131099,
0.30058158224,
0.298916777049,
0.297256732019,
0.295601463421,
0.293950987306,
0.2923053195,
0.290664475608,
0.289028471014,
0.28739732088,
0.285771040146,
0.28414964353,
0.282533145532,
0.280921560429,
0.279314902278,
0.277713184915,
0.276116421958,
0.274524626803,
0.27293781263,
0.271355992396,
0.269779178843,
0.268207384491,
0.266640621645,
0.26507890239,
0.263522238595,
0.261970641912,
0.260424123775,
0.258882695403,
0.257346367799,
0.255815151751,
0.254289057829,
0.252768096393,
0.251252277584,
0.249741611333,
0.248236107356,
0.246735775155,
0.245240624022,
0.243750663036,
0.242265901062,
0.240786346759,
0.239312008571,
0.237842894734,
0.236379013274,
0.234920372009,
0.233466978548,
0.23201884029,
0.23057596443,
0.229138357954,
0.227706027644,
0.226278980072,
0.224857221611,
0.223440758423,
0.222029596471,
0.220623741513,
0.219223199104,
0.217827974596,
0.216438073143,
0.215053499695,
0.213674259002,
0.212300355615,
0.210931793888,
0.209568577975,
0.208210711831,
0.206858199217,
0.205511043696,
0.204169248637,
0.202832817213,
0.201501752404,
0.200176056994,
0.198855733579,
0.197540784558,
0.196231212143,
0.194927018353,
0.193628205019,
0.192334773782,
0.191046726094,
0.189764063223,
0.188486786246,
0.187214896057,
0.185948393365,
0.184687278693,
0.183431552382,
0.18218121459,
0.180936265292,
0.179696704284,
0.17846253118,
0.177233745417,
0.17601034625,
0.174792332759,
0.173579703845,
0.172372458237,
0.171170594483,
0.169974110962,
0.168783005877,
0.167597277257,
0.166416922963,
0.165241940683,
0.164072327935,
0.162908082068,
0.161749200263,
0.160595679535,
0.159447516731,
0.158304708533,
0.157167251458,
0.156035141862,
0.154908375934,
0.153786949706,
0.152670859044,
0.15156009966,
0.150454667101,
0.149354556761,
0.148259763875,
0.14717028352,
0.146086110621,
0.145007239947,
0.143933666115,
0.142865383587,
0.141802386678,
0.140744669548,
0.139692226212,
0.138645050534,
0.13760313623,
0.136566476872,
0.135535065885,
0.13450889655,
0.133487962004,
0.132472255243,
0.131461769119,
0.130456496347,
0.1294564295,
0.128461561013,
0.127471883183,
0.126487388174,
0.12550806801,
0.124533914583,
0.123564919652,
0.122601074842,
0.121642371649,
0.120688801437,
0.11974035544,
0.118797024767,
0.117858800396,
0.116925673181,
0.115997633851,
0.115074673009,
0.114156781138,
0.113243948596,
0.112336165622,
0.111433422334,
0.110535708732,
0.109643014696,
0.108755329993,
0.10787264427,
0.106994947062,
0.10612222779,
0.105254475762,
0.104391680174,
0.103533830112,
0.102680914552,
0.101832922363,
0.100989842306,
0.100151663034,
0.0993183730966,
0.0984899609391,
0.0976664149028,
0.0968477232276,
0.0960338740519,
0.0952248554145,
0.0944206552549,
0.093621261415,
0.0928266616397,
0.0920368435781,
0.0912517947848,
0.0904715027205,
0.0896959547534,
0.0889251381601,
0.0881590401266,
0.0873976477496,
0.0866409480373,
0.0858889279106,
0.0851415742039,
0.0843988736666,
0.0836608129638,
0.0829273786772,
0.0821985573067,
0.0814743352709,
0.0807546989085,
0.0800396344791,
0.0793291281645,
0.0786231660694,
0.0779217342228,
0.0772248185787,
0.0765324050174,
0.0758444793464,
0.0751610273015,
0.0744820345478,
0.0738074866807,
0.073137369227,
0.0724716676458,
0.0718103673297,
0.0711534536058,
0.0705009117364,
0.0698527269205,
0.0692088842945,
0.0685693689333,
0.0679341658515,
0.0673032600038,
0.066676636287,
0.0660542795399,
0.0654361745453,
0.0648223060303,
0.0642126586676,
0.0636072170764,
0.0630059658236,
0.0624088894244,
0.0618159723438,
0.0612271989971,
0.0606425537512,
0.0600620209255,
0.0594855847926,
0.05891322958,
0.0583449394702,
0.0577806986022,
0.0572204910724,
0.0566643009355,
0.0561121122055,
0.0555639088565,
0.0550196748238,
0.0544793940051,
0.0539430502608,
0.0534106274157,
0.0528821092593,
0.0523574795472,
0.0518367220016,
0.0513198203129,
0.0508067581399,
0.050297519111,
0.0497920868255,
0.0492904448538,
0.048792576739,
0.0482984659974,
0.0478080961194,
0.0473214505707,
0.0468385127931,
0.046359266205,
0.0458836942029,
0.045411780162,
0.044943507437,
0.0444788593631,
0.0440178192568,
0.0435603704171,
0.0431064961259,
0.0426561796489,
0.042209404237,
0.0417661531267,
0.0413264095408,
0.0408901566898,
0.0404573777723,
0.0400280559761,
0.0396021744789,
0.0391797164491,
0.0387606650467,
0.0383450034242,
0.0379327147274,
0.0375237820961,
0.0371181886648,
0.0367159175641,
0.0363169519207,
0.0359212748589,
0.0355288695009,
0.0351397189678,
0.0347538063805,
0.0343711148603,
0.0339916275297,
0.0336153275133,
0.0332421979385,
0.032872221936,
0.0325053826411,
0.0321416631941,
0.0317810467411,
0.0314235164347,
0.031069055435,
0.0307176469099,
0.0303692740364,
0.0300239200008,
0.0296815679997,
0.0293422012405,
0.0290058029427,
0.0286723563378,
0.0283418446706,
0.0280142511996,
0.0276895591978,
0.0273677519536,
0.027048812771,
0.0267327249706,
0.0264194718906,
0.0261090368866,
0.0258014033331,
0.0254965546239,
0.0251944741724,
0.024895145413,
0.024598551801,
0.0243046768137,
0.0240135039507,
0.0237250167352,
0.0234391987136,
0.0231560334572,
0.022875504562,
0.0225975956498,
0.0223222903686,
0.0220495723932,
0.0217794254262,
0.0215118331977,
0.021246779467,
0.0209842480223,
0.0207242226818,
0.020466687294,
0.0202116257385,
0.0199590219264,
0.019708859801,
0.0194611233381,
0.0192157965469,
0.0189728634704,
0.0187323081859,
0.0184941148054,
0.0182582674767,
0.0180247503831,
0.0177935477448,
0.0175646438187,
0.0173380228993,
0.0171136693193,
0.0168915674497,
0.0166717017006,
0.0164540565217,
0.0162386164028,
0.016025365874,
0.0158142895067,
0.0156053719137,
0.0153985977495,
0.0151939517116,
0.0149914185398,
0.0147909830177,
0.0145926299727,
0.0143963442761,
0.0142021108445,
0.0140099146393,
0.0138197406675,
0.0136315739824,
0.0134453996837,
0.0132612029178,
0.0130789688788,
0.0128986828081,
0.0127203299958,
0.0125438957802,
0.0123693655486,
0.0121967247377,
0.0120259588342,
0.0118570533747,
0.0116899939465,
0.0115247661877,
0.0113613557878,
0.011199748488,
0.0110399300815,
0.0108818864139,
0.0107256033838,
0.0105710669426,
0.0104182630955,
0.0102671779014,
0.0101177974733,
0.00997010797882,
0.00982409564054,
0.00967974673608,
0.00953704759866,
0.00939598461731,
0.00925654423725,
0.00911871296017,
0.00898247734457,
0.00884782400604,
0.00871473961758,
0.00858321090989,
0.00845322467169,
0.00832476774997,
0.00819782705033,
0.00807238953722,
0.00794844223425,
0.00782597222445,
0.00770496665056,
0.00758541271527,
0.00746729768152,
0.00735060887275,
0.00723533367315,
0.00712145952792,
0.00700897394352,
0.00689786448792,
0.00678811879085,
0.00667972454404,
0.00657266950144,
0.00646694147945,
0.0063625283572,
0.00625941807672,
0.00615759864319,
0.00605705812515,
0.00595778465473,
0.00585976642785,
0.00576299170443,
0.0056674488086,
0.00557312612892,
0.00548001211855,
0.00538809529546,
0.00529736424264,
0.00520780760825,
0.00511941410586,
0.00503217251459,
0.00494607167932,
0.00486110051083,
0.00477724798605,
0.00469450314814,
0.00461285510673,
0.00453229303805,
0.00445280618509,
0.00437438385781,
0.00429701543323,
0.00422069035563,
0.00414539813669,
0.00407112835563,
0.00399787065938,
0.0039256147627,
0.00385435044832,
0.00378406756712,
0.0037147560382,
0.00364640584907,
0.00357900705577,
0.00351254978296,
0.00344702422409,
0.00338242064152,
0.0033187293666,
0.00325594079984,
0.00319404541099,
0.00313303373919,
0.00307289639303,
0.0030136240507,
0.0029552074601,
0.0028976374389,
0.00284090487469,
0.00278500072507,
0.00272991601772,
0.00267564185053,
0.00262216939169,
0.00256948987974,
0.00251759462373,
0.00246647500324,
0.00241612246851,
0.0023665285405,
0.002317684811,
0.00226958294266,
0.00222221466913,
0.00217557179509,
0.00212964619633,
0.00208442981986,
0.00203991468391,
0.00199609287809,
0.00195295656337,
0.00191049797221,
0.00186870940858,
0.00182758324806,
0.00178711193786,
0.00174728799692,
0.00170810401592,
0.00166955265741,
0.00163162665578,
0.00159431881735,
0.00155762202045,
0.00152152921544,
0.00148603342472,
0.00145112774288,
0.00141680533665,
0.00138305944497,
0.00134988337907,
0.00131727052248,
0.00128521433106,
0.00125370833306,
0.00122274612918,
0.00119232139254,
0.00116242786879,
0.0011330593761,
0.00110420980521,
0.00107587311944,
0.00104804335476,
0.0010207146198,
0.000993881095876,
0.000967537037019,
0.000941676770012,
0.000916294694407,
0.000891385282558,
0.000866943079641,
0.000842962703681,
0.000819438845571,
0.000796366269098,
0.000773739810963,
0.000751554380802,
0.000729804961205,
0.000708486607736,
0.000687594448949,
0.000667123686408,
0.000647069594704,
0.00062742752147,
0.000608192887396,
0.000589361186245,
0.000570927984867,
0.000552888923211,
0.000535239714341,
0.000517976144447,
0.000501094072855,
0.000484589432043,
0.000468458227646,
0.000452696538471,
0.000437300516505,
0.000422266386923,
0.000407590448099,
0.000393269071616,
0.000379298702269,
0.000365675858076,
0.000352397130287,
0.000339459183385,
0.000326858755099,
0.000314592656405,
0.000302657771537,
0.000291051057985,
0.000279769546509,
0.000268810341137,
0.000258170619172,
0.000247847631197,
0.000237838701079,
0.000228141225971,
0.000218752676317,
0.000209670595855,
0.00020089260162,
0.000192416383947,
0.000184239706475,
0.000176360406146,
0.00016877639321,
0.000161485651229,
0.000154486237074,
0.00014777628093,
0.000141353986299,
0.000135217629998,
0.000129365562164,
0.000123796206252,
0.000118508059038,
0.000113499690623,
0.000108769744427,
0.000104316937196,
0.000100140059002,
9.62379732402e-05,
9.26096166338e-05,
8.92539992328e-05,
8.61702044144e-05,
8.33573888843e-05,
8.08147826765e-05,
7.85416891538e-05,
7.65374850087e-05,
7.48016202632e-05,
7.33336182689e-05,
7.2133075708e-05,
7.11996625926e-05,
7.05331222657e-05,
7.01332714001e-05,
7e-05};
#endif