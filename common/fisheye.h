// Fisheye.h - functions to work with fisheye lens mapping
#pragma once
#include<cmath>

const double AngleToHeightNormalized[] = { 0.0, 0.0018917849287185039, 0.0037835698574370078, 0.005675354786155511, 0.0075671397148740155, 0.00945892464359252, 0.011350709572311022, 0.013242463292373498, 0.015134036447795767, 0.017025609603218035,
0.0189171827586403, 0.02080875591406257, 0.022700329069484836, 0.024591902224907106, 0.02648334961065836, 0.028374496047571945, 0.030265642484485523, 0.032156788921399095, 0.03404793535831267, 0.03593908179522625,
0.03783022823213983, 0.03972109477382181, 0.04161160811412371, 0.04350212145442562, 0.04539263479472752, 0.04728314813502943, 0.04917366147533133, 0.051064174815633245, 0.05295418705900353, 0.054843850324189355,
0.056733513589375194, 0.05862317685456101, 0.06051284011974685, 0.062402503384932674, 0.0642921666501185, 0.06618104788020925, 0.06806964981181365, 0.06995825174341805, 0.07184685367502243, 0.07373545560662684,
0.07562405753823122, 0.07751265946983561, 0.07940013218336328, 0.08128745702314889, 0.08317478186293452, 0.08506210670272016, 0.08694943154250578, 0.08883675638229141, 0.09072403447861185, 0.09260987910149941,
0.09449572372438698, 0.09638156834727454, 0.0982674129701621, 0.10015325759304966, 0.10203910221593722, 0.10392464334850983, 0.10580879199657796, 0.10769294064464607, 0.10957708929271422, 0.11146123794078233,
0.11334538658885047, 0.11522953523691858, 0.11711306152471346, 0.11899530293886486, 0.12087754435301627, 0.12275978576716767, 0.12464202718131906, 0.12652426859547047, 0.12840651000962186, 0.13028774772251636,
0.13216787021206935, 0.13404799270162235, 0.13592811519117534, 0.13780823768072833, 0.13968836017028133, 0.14156848265983432, 0.14344716050839615, 0.14532495688061908, 0.14720275325284202, 0.14908054962506498,
0.15095834599728788, 0.15283614236951085, 0.15471393874173373, 0.15658978188401995, 0.1584650363819137, 0.1603402908798075, 0.16221554537770122, 0.16409079987559502, 0.1659660543734888, 0.16784130887138257,
0.16971404952676383, 0.17158655902386596, 0.17345906852096815, 0.1753315780180703, 0.17720408751517247, 0.1790765970122746, 0.1809489195139292, 0.18281846825384648, 0.18468801699376378, 0.18655756573368104,
0.18842711447359833, 0.1902966632135156, 0.1921662119534329, 0.19403509290042417, 0.19590146962238622, 0.1977678463443483, 0.19963422306631035, 0.20150059978827245, 0.20336697651023453, 0.2052333532321966,
0.20709852330945042, 0.20896152852507394, 0.21082453374069735, 0.21268753895632087, 0.21455054417194433, 0.21641354938756782, 0.21827655460319131, 0.22013774752372073, 0.22199716590465848, 0.2238565842855962,
0.22571600266653394, 0.22757542104747167, 0.2294348394284094, 0.2312942578093471, 0.23315119980809962, 0.235006823733112, 0.23686244765812445, 0.23871807158313685, 0.24057369550814925, 0.24242931943316168,
0.24428494335817405, 0.24613736596232924, 0.24798898823587734, 0.2498406105094254, 0.25169223278297354, 0.2535438550565216, 0.2553954773300697, 0.2572470996036178, 0.2590947302926713, 0.2609421392275822,
0.26278954816249295, 0.26463695709740376, 0.26648436603231457, 0.2683317749672254, 0.27017876704128146, 0.2720217757752097, 0.2738647845091379, 0.2757077932430662, 0.2775508019769945, 0.27939381071092273,
0.281236819444851, 0.28307870472378854, 0.2849170731027608, 0.2867554414817331, 0.2885938098607054, 0.29043217823967765, 0.29227054661865, 0.29410891499762226, 0.29594539855057794, 0.297778927510732,
0.29961245647088597, 0.3014459854310399, 0.303279514391194, 0.305113043351348, 0.30694657231150196, 0.30877739399213217, 0.3106058799820219, 0.3124343659719115, 0.31426285196180115, 0.31609133795169087,
0.3179198239415805, 0.3197483099314702, 0.3215732064118318, 0.32339644619517155, 0.32521968597851114, 0.3270429257618508, 0.3288661655451904, 0.3306894053285301, 0.3325126451118697, 0.3343313532537836,
0.3361491435933858, 0.33796693393298793, 0.3397847242725901, 0.34160251461219227, 0.34342030495179443, 0.34523809529139665, 0.3470503516481693, 0.3488624889943914, 0.3506746263406136, 0.3524867636868357,
0.3542989010330578, 0.35611103837927993, 0.35792243086843434, 0.3597286714193111, 0.3615349119701879, 0.36334115252106475, 0.3651473930719415, 0.36695363362281824, 0.3687598741736951, 0.3705644562871951,
0.3723646371626753, 0.37416481803815554, 0.3759649989136357, 0.377765179789116, 0.3795653606645961, 0.3813655415400763, 0.38316306832055097, 0.38495694571729916, 0.38675082311404735, 0.38854470051079554,
0.39033857790754384, 0.392132455304292, 0.3939263327010402, 0.3957165113674547, 0.3975038817385686, 0.39929125210968247, 0.4010786224807964, 0.4028659928519102, 0.40465336322302414, 0.406440733594138,
0.408223300903109, 0.41000396111205534, 0.4117846213210016, 0.4135652815299478, 0.4153459417388941, 0.41712660194784046, 0.4189072621567867, 0.42068195474441755, 0.4224557012458084, 0.4242294477471994,
0.4260031942485903, 0.42777694074998124, 0.42955068725137224, 0.4313243584118129, 0.4330909473992839, 0.43485753638675495, 0.4366241253742259, 0.43839071436169696, 0.4401573033491679, 0.44192389233663887,
0.44368932547299644, 0.44544859407104, 0.4472078626690835, 0.4489671312671271, 0.4507263998651707, 0.4524856684632143, 0.4542449370612578, 0.45600188417526466, 0.45775354790758704, 0.4595052116399093,
0.4612568753722317, 0.4630085391045541, 0.4647602028368764, 0.46651186656919874, 0.4682600143770613, 0.47000391036986516, 0.4717478063626692, 0.4734917023554731, 0.4752355983482771, 0.47697949434108106,
0.47872339033388495, 0.480462479398365, 0.48219836384186543, 0.4839342482853657, 0.48567013272886606, 0.48740601717236637, 0.4891419016158668, 0.4908777860593671, 0.4926075004097994, 0.49433512909547156,
0.4960627577811436, 0.49779038646681567, 0.4995180151524878, 0.50124564383816, 0.5029732725238321, 0.5046933327201737, 0.5064125025046383, 0.508131672289103, 0.5098508420735678, 0.5115700118580324,
0.5132891816424971, 0.5150079866921639, 0.5167184940370796, 0.5184290013819953, 0.5201395087269112, 0.521850016071827, 0.5235605234167428, 0.5252710307616586, 0.5269798351960303, 0.5286813549512457,
0.530382874706461, 0.5320843944616763, 0.5337859142168916, 0.5354874339721071, 0.5371889537273223, 0.5388874049212294, 0.540579814886961, 0.5422722248526927, 0.5439646348184242, 0.5456570447841559,
0.5473494547498875, 0.549041864715619, 0.5507297061843907, 0.5524126812084132, 0.5540956562324356, 0.5557786312564581, 0.5574616062804806, 0.5591445813045031, 0.5608275563285255, 0.5625044182080611,
0.5641777140879127, 0.5658510099677644, 0.5675243058476162, 0.5691976017274678, 0.5708708976073193, 0.5725441934871711, 0.5742097599029162, 0.5758731328207216, 0.5775365057385271, 0.5791998786563325,
0.580863251574138, 0.5825266244919435, 0.584189997409749, 0.5858439899953133, 0.587497236419125, 0.5891504828429365, 0.5908037292667481, 0.5924569756905598, 0.5941102221143714, 0.59576269542094,
0.5974054495257745, 0.5990482036306088, 0.6006909577354433, 0.6023337118402777, 0.6039764659451122, 0.6056192200499467, 0.6072596098081602, 0.6088916680644326, 0.610523726320705, 0.6121557845769772,
0.6137878428332496, 0.6154199010895218, 0.6170519593457943, 0.6186799571975002, 0.6203009943531906, 0.6219220315088813, 0.6235430686645718, 0.6251641058202623, 0.6267851429759529, 0.6284061801316434,
0.6300214069127242, 0.6316311790504592, 0.633240951188194, 0.634850723325929, 0.6364604954636637, 0.6380702676013985, 0.6396800397391335, 0.6412820985444178, 0.64288023946532, 0.6444783803862225,
0.6460765213071249, 0.6476746622280274, 0.6492728031489298, 0.6508709440698321, 0.6524594599587147, 0.6540457258362972, 0.6556319917138796, 0.6572182575914622, 0.6588045234690447, 0.6603907893466272,
0.6619770552242098, 0.6635515952836081, 0.6651256199216875, 0.666699644559767, 0.6682736691978463, 0.6698476938359259, 0.6714217184740053, 0.6729944246165566, 0.6745559235176118, 0.676117422418667,
0.6776789213197222, 0.6792404202207774, 0.6808019191218325, 0.6823634180228878, 0.6839216600158041, 0.68547026698649, 0.6870188739571759, 0.6885674809278619, 0.6901160878985478, 0.6916646948692338,
0.6932133018399197, 0.6947565894394929, 0.6962918979745653, 0.6978272065096374, 0.6993625150447096, 0.700897823579782, 0.7024331321148543, 0.7039684406499266, 0.7054963141217645, 0.7070180393674148,
0.7085397646130656, 0.710061489858716, 0.7115832151043663, 0.7131049403500168, 0.7146266655956672, 0.7161386716165319, 0.7176464070644359, 0.7191541425123397, 0.7206618779602438, 0.7221696134081478,
0.7236773488560516, 0.7251850843039557, 0.7266806620077653, 0.7281739601342027, 0.7296672582606403, 0.7311605563870779, 0.7326538545135153, 0.7341471526399528, 0.7356404507663903, 0.7371191015539569,
0.7385975965156159, 0.7400760914772749, 0.7415545864389339, 0.743033081400593, 0.7445115763622521, 0.745987989953306, 0.747451274898085, 0.7489145598428644, 0.7503778447876437, 0.7518411297324229,
0.7533044146772021, 0.7547676996219815, 0.756226523070423, 0.7576741101467607, 0.7591216972230983, 0.7605692842994359, 0.7620168713757737, 0.7634644584521112, 0.7649120455284489, 0.766352682147909,
0.7677841645072454, 0.7692156468665818, 0.7706471292259184, 0.7720786115852546, 0.7735100939445912, 0.7749415763039276, 0.7763634288955548, 0.7777782780144138, 0.7791931271332728, 0.7806079762521317,
0.7820228253709909, 0.7834376744898498, 0.7848525236087088, 0.7862549667062835, 0.7876527350715892, 0.7890505034368949, 0.7904482718022005, 0.7918460401675063, 0.7932438085328117, 0.7946415768981174,
0.7960239603158049, 0.7974041194002176, 0.7987842784846302, 0.800164437569043, 0.8015445966534557, 0.8029247557378684, 0.8043045338226362, 0.8056665954487875, 0.8070286570749386, 0.8083907187010899,
0.8097527803272412, 0.8111148419533923, 0.8124769035795435, 0.8138358213505202, 0.8151792163187086, 0.8165226112868967, 0.817866006255085, 0.8192094012232732, 0.8205527961914615, 0.8218961911596497,
0.8232335115477838, 0.8245576703483176, 0.8258818291488518, 0.8272059879493856, 0.8285301467499195, 0.8298543055504535, 0.8311784643509875, 0.8324934689760319, 0.833797863073137, 0.835102257170242,
0.8364066512673469, 0.837711045364452, 0.839015439461557, 0.840319833558662, 0.8416118130851823, 0.8428958729736362, 0.84417993286209, 0.845463992750544, 0.8467480526389978, 0.8480321125274519,
0.8493161724159056, 0.8505843588950014, 0.8518474746978942, 0.853110590500787, 0.8543737063036798, 0.8556368221065728, 0.8568999379094654, 0.8581630537123583, 0.8594066940569804, 0.8606482962738201,
0.8618898984906599, 0.8631315007074997, 0.8643731029243396, 0.8656147051411792, 0.8668551408236108, 0.8680745788344835, 0.869294016845356, 0.8705134548562284, 0.8717328928671011, 0.8729523308779735,
0.8741717688888463, 0.8753866602082293, 0.8765833647259511, 0.877780069243673, 0.878976773761395, 0.8801734782791168, 0.8813701827968389, 0.8825668873145608, 0.8837554829865516, 0.8849288438499731,
0.8861022047133946, 0.8872755655768162, 0.8884489264402379, 0.8896222873036593, 0.8907956481670809, 0.8919571583370652, 0.8931065656565912, 0.8942559729761174, 0.8954053802956434, 0.8965547876151695,
0.8977041949346956, 0.8988536022542216, 0.8999872109820674, 0.9011120139337003, 0.9022368168853332, 0.9033616198369662, 0.9044864227885991, 0.905611225740232, 0.9067360286918651, 0.9078409898666804,
0.9089406598918011, 0.9100403299169216, 0.9111399999420423, 0.9122396699671629, 0.9133393399922837, 0.9144390100174041, 0.9155145628467349, 0.9165884897953129, 0.9176624167438909, 0.9187363436924689,
0.919810270641047, 0.920884197589625, 0.9219559053473924, 0.9230034793184384, 0.9240510532894843, 0.9250986272605303, 0.9261462012315762, 0.9271937752026224, 0.9282413491736683, 0.9292827073091388,
0.9303034401633955, 0.9313241730176524, 0.9323449058719091, 0.933365638726166, 0.9343863715804228, 0.9354071044346797, 0.9364174656251862, 0.9374108287921092, 0.9384041919590321, 0.9393975551259551,
0.940390918292878, 0.941384281459801, 0.942377644626724, 0.9433563457846482, 0.9443218511311923, 0.9452873564777364, 0.9462528618242807, 0.9472183671708247, 0.9481838725173689, 0.949149377863913,
0.9500957871475524, 0.9510329467651143, 0.9519701063826765, 0.9529072660002387, 0.9538444256178008, 0.9547815852353629, 0.9557187448529252, 0.9566323305312683, 0.9575407782980474, 0.9584492260648265,
0.9593576738316056, 0.9602661215983848, 0.9611745693651638, 0.9620830171319429, 0.9629632660056668, 0.9638425953430617, 0.9647219246804567, 0.9656012540178516, 0.9664805833552464, 0.9673599126926414,
0.9682164224243233, 0.9688986732854339, 0.9695809241465443, 0.9702631750076549, 0.9709454258687653, 0.9716276767298758, 0.9723099275909863, 0.9730725731417406, 0.9740603240873813, 0.9750480750330223,
0.9760358259786632, 0.9770235769243042, 0.9780113278699449, 0.9789990788155859, 0.9799057235180555, 0.9806959079619859, 0.9814860924059162, 0.9822762768498466, 0.9830664612937772, 0.9838566457377076,
0.9846468301816381, 0.9854202250830243, 0.9861803150523106, 0.9869404050215971, 0.9877004949908834, 0.9884605849601699, 0.9892206749294563, 0.9899807648987428, 0.9907195155554293, 0.9914493482899005,
0.9921791810243716, 0.992909013758843, 0.9936388464933142, 0.9943686792277854, 0.9950985119622565, 0.995802546500268, 0.9965021220835567, 0.9972016976668453, 0.997901273250134, 0.9986008488334227,
0.9993004244167113, 1.0 };

const double HeightToAngleNormalized[] = { 0, 0.0012472866143826912, 0.0024945732287653824, 0.0037418598431480737, 0.004989146457530765, 0.0062364330719134565, 0.007483719686296147, 0.008731006300678839, 0.00997829291506153, 0.011225657816305547,
0.012473084072127386, 0.013720510327949227, 0.014967936583771067, 0.01621536283959291, 0.01746278909541475, 0.018710215351236587, 0.01995764160705843, 0.021205102258625944, 0.022452809983857656, 0.02370051770908937,
0.024948225434321087, 0.026195933159552803, 0.027443640884784515, 0.02869134861001623, 0.029939056335247946, 0.031186764060479665, 0.03243475828431756, 0.0336828838429051, 0.03493100940149264, 0.03617913496008017,
0.0374272605186677, 0.03867538607725525, 0.039923511635842776, 0.041171637194430316, 0.04241990423235819, 0.04366859126689683, 0.044917278301435465, 0.04616596533597412, 0.047414652370512754, 0.04866333940505141,
0.04991202643959004, 0.0511607134741287, 0.05240940050866733, 0.053658664407899716, 0.05490805316441603, 0.05615744192093233, 0.057406830677448624, 0.058656219433964936, 0.05990560819048124, 0.06115499694699755,
0.06240438570351386, 0.06365411000587642, 0.06490434418344891, 0.06615457836102139, 0.06740481253859389, 0.06865504671616636, 0.06990528089373886, 0.07115551507131133, 0.07240574924888384, 0.07365598342645631,
0.07490717676850943, 0.07615839226645887, 0.07740960776440829, 0.0786608232623577, 0.07991203876030713, 0.08116325425825656, 0.08241446975620598, 0.08366568525415541, 0.08491753657953147, 0.08616987833149507,
0.08742222008345868, 0.08867456183542229, 0.08992690358738589, 0.0911792453393495, 0.09243158709131312, 0.09368392884327673, 0.0949364726715338, 0.09619008339391039, 0.09744369411628702, 0.09869730483866361,
0.09995091556104023, 0.10120452628341685, 0.10245813700579344, 0.10371174772817005, 0.10496535845054664, 0.10622004638583987, 0.10747506994520514, 0.10873009350457043, 0.10998511706393568, 0.111240140623301,
0.11249516418266625, 0.11375018774203152, 0.11500521130139679, 0.1162608180151922, 0.11751739623303602, 0.11877397445087987, 0.12003055266872369, 0.12128713088656752, 0.12254370910441136, 0.12380028732225518,
0.125056865540099, 0.12631344375794284, 0.12757172206593118, 0.12883000355334087, 0.1300882850407506, 0.13134656652816026, 0.13260484801556996, 0.13386312950297963, 0.13512141099038935, 0.13637969247779905,
0.1376391406667569, 0.13889926672888533, 0.14015939279101383, 0.14141951885314227, 0.14267964491527074, 0.1439397709773992, 0.14519989703952768, 0.14646002310165615, 0.14772070618693392, 0.1489828278789236,
0.15024494957091325, 0.1515070712629029, 0.15276919295489252, 0.1540313146468822, 0.15529343633887183, 0.15655555803086146, 0.1578176797228511, 0.15908181550211217, 0.16034608224478827, 0.16161034898746438,
0.1628746157301405, 0.1641388824728166, 0.1654031492154927, 0.16666741595816884, 0.16793168270084496, 0.16919735178528855, 0.17046390648899712, 0.17173046119270566, 0.17299701589641425, 0.1742635706001228,
0.17553012530383136, 0.1767966800075399, 0.1780632347112485, 0.17933052710820482, 0.18059952500726378, 0.18186852290632272, 0.1831375208053816, 0.18440651870444055, 0.18567551660349946, 0.18694451450255833,
0.1882135124016173, 0.18948252834897794, 0.19075412114699905, 0.19202571394502022, 0.19329730674304132, 0.19456889954106246, 0.19584049233908365, 0.19711208513710476, 0.19838367793512593, 0.19965527073314712,
0.20092886663103207, 0.20220320754418175, 0.2034775484573314, 0.204751889370481, 0.20602623028363068, 0.20730057119678028, 0.20857491210992993, 0.2098492530230796, 0.2111249561337632, 0.21240220340386773,
0.21367945067397226, 0.21495669794407674, 0.21623394521418124, 0.21751119248428571, 0.21878843975439025, 0.22006568702449478, 0.2213436273948674, 0.2226239241050475, 0.2239042208152276, 0.22518451752540763,
0.22646481423558773, 0.22774511094576785, 0.22902540765594787, 0.230305704366128, 0.23158601888159716, 0.23286954727877332, 0.2341530756759494, 0.23543660407312547, 0.23672013247030158, 0.2380036608674777,
0.2392871892646538, 0.24057071766182989, 0.241854246059006, 0.24314049966768195, 0.24442741581144625, 0.24571433195521047, 0.24700124809897475, 0.24828816424273903, 0.2495750803865033, 0.25086199653026753,
0.2521489126740319, 0.253438046942166, 0.25472851240481026, 0.25601897786745453, 0.25730944333009875, 0.258599908792743, 0.2598903742553873, 0.2611808397180316, 0.26247130518067585, 0.26376350824110173,
0.26505768690067405, 0.2663518655602465, 0.2676460442198188, 0.26894022287939123, 0.2702344015389635, 0.27152858019853593, 0.2728227588581083, 0.27411823476269526, 0.27541629316221233, 0.27671435156172935,
0.2780124099612464, 0.2793104683607634, 0.2806085267602804, 0.28190658515979744, 0.2832046435593145, 0.284503613405598, 0.2858057211204469, 0.2871078288352957, 0.28840993655014446, 0.28971204426499325,
0.29101415197984215, 0.29231625969469094, 0.2936183674095398, 0.29492107462612593, 0.29622743330450685, 0.2975337919828879, 0.2988401506612688, 0.30014650933964976, 0.3014528680180307, 0.30275922669641164,
0.30406558537479256, 0.3053723102434064, 0.30668306631854364, 0.30799382239368084, 0.30930457846881804, 0.31061533454395523, 0.3119260906190925, 0.31323684669422963, 0.3145476027693669, 0.3158586008979146,
0.31717396281905746, 0.31848932474020036, 0.3198046866613432, 0.32112004858248605, 0.32243541050362895, 0.32375077242477185, 0.3250661343459147, 0.3263817354764315, 0.32770188604903555, 0.32902203662163965,
0.33034218719424374, 0.3316623377668477, 0.3329824883394518, 0.33430263891205586, 0.33562278948465996, 0.3369433200375741, 0.33826844540794326, 0.3395935707783123, 0.3409186961486815, 0.3422438215190506,
0.34356894688941975, 0.3448940722597888, 0.34621919763015796, 0.3475450086310346, 0.3488752990739086, 0.3502055895167825, 0.3515358799596565, 0.35286617040253043, 0.35419646084540446, 0.35552675128827843,
0.3568570417311524, 0.35818851765246906, 0.35952419790159107, 0.3608598781507132, 0.3621955583998352, 0.36353123864895726, 0.3648669188980792, 0.3662025991472013, 0.36753827939632333, 0.3688758442104015,
0.37021708228030487, 0.3715583203502082, 0.37289955842011147, 0.3742407964900148, 0.3755820345599181, 0.37692327262982145, 0.37826451069972483, 0.3796086071334067, 0.3809556682018878, 0.38230272927036874,
0.3836497903388497, 0.38499685140733064, 0.38634391247581173, 0.38769097354429255, 0.3890380346127736, 0.39038915533121205, 0.3917422165393451, 0.393095277747478, 0.3944483389556109, 0.3958014001637439,
0.39715446137187677, 0.3985075225800097, 0.3998605837881427, 0.401219246276262, 0.40257855220685906, 0.40393785813745636, 0.4052971640680536, 0.4066564699986509, 0.4080157759292481, 0.4093750818598453,
0.41073538209705573, 0.41210118369461574, 0.41346698529217585, 0.4148327868897359, 0.416198588487296, 0.4175643900848559, 0.418930191682416, 0.4202959932799761, 0.42166479216746583, 0.423037313974331,
0.4244098357811961, 0.4257823575880614, 0.4271548793949266, 0.4285274012017917, 0.4298999230086569, 0.43127244481552207, 0.432650365212544, 0.4340298378151582, 0.43540931041777226, 0.4367887830203864,
0.43816825562300044, 0.43954772822561444, 0.44092720082822856, 0.4423077372980492, 0.443694496406575, 0.44508125551510086, 0.4464680146236266, 0.44785477373215243, 0.4492415328406783, 0.4506282919492041,
0.45201505105773, 0.45340595611515894, 0.4548001797764817, 0.4561944034378045, 0.4575886270991273, 0.4589828507604501, 0.4603770744217729, 0.4617712980830957, 0.46316556450122337, 0.4645676043325941,
0.46596964416396475, 0.4673716839953354, 0.4687737238267061, 0.47017576365807673, 0.47157780348944733, 0.472979843320818, 0.4743859188252817, 0.4757960687260217, 0.47720621862676166, 0.4786163685275017,
0.4800265184282418, 0.48143666832898185, 0.4828468182297218, 0.4842572451812191, 0.48567580742521343, 0.4870943696692077, 0.48851293191320205, 0.48993149415719645, 0.4913500564011907, 0.49276861864518495,
0.4941871808891794, 0.49561106534188515, 0.4970383165882186, 0.49846556783455215, 0.4998928190808856, 0.501320070327219, 0.5027473215735525, 0.504174572819886, 0.5056039871361249, 0.5070403542783146,
0.5084767214205042, 0.5099130885626939, 0.5113494557048838, 0.5127858228470734, 0.5142221899892632, 0.5156585571314529, 0.5171034796689673, 0.5185492601794441, 0.5199950406899211, 0.521440821200398,
0.522886601710875, 0.5243323822213517, 0.5257781627318286, 0.5272301175934568, 0.5286857276703747, 0.5301413377472927, 0.5315969478242105, 0.5330525579011285, 0.5345081679780465, 0.5359637780549643,
0.5374234278944108, 0.5388892241792204, 0.5403550204640296, 0.5418208167488391, 0.5432866130336487, 0.5447524093184581, 0.5462182056032675, 0.5476862986741875, 0.5491627629759396, 0.5506392272776915,
0.5521156915794435, 0.5535921558811955, 0.5550686201829477, 0.5565450844846995, 0.5580224981182151, 0.5595100154709036, 0.560997532823592, 0.5624850501762804, 0.5639725675289686, 0.5654600848816572,
0.5669476022343456, 0.5684352289855013, 0.5699343148077922, 0.5714334006300832, 0.572932486452374, 0.574431572274665, 0.5759306580969561, 0.5774297439192471, 0.5789288297415379, 0.5804397919342691,
0.5819509028401347, 0.5834620137460002, 0.5849731246518657, 0.5864842355577312, 0.5879953464635966, 0.5895067302007168, 0.5910304208876033, 0.5925541115744898, 0.5940778022613761, 0.5956014929482625,
0.5971251836351489, 0.5986488743220354, 0.6001740597181582, 0.6017109482099363, 0.6032478367017146, 0.6047847251934928, 0.606321613685271, 0.6078585021770493, 0.6093953906688275, 0.610935902887879,
0.6124865100198996, 0.6140371171519202, 0.6155877242839409, 0.6171383314159616, 0.6186889385479822, 0.6202395456800028, 0.6217969960338253, 0.6233619907563157, 0.6249269854788062, 0.6264919802012967,
0.6280569749237872, 0.6296219696462777, 0.631186964368768, 0.632763299858764, 0.6343434250709415, 0.6359235502831192, 0.6375036754952966, 0.6390838007074743, 0.6406639259196519, 0.6422454407182047,
0.6438413866497578, 0.6454373325813109, 0.647033278512864, 0.648629224444417, 0.6502251703759702, 0.6518211163075232, 0.6534252268921572, 0.655037761776289, 0.6566502966604209, 0.6582628315445528,
0.6598753664286846, 0.6614879013128163, 0.6631004361969485, 0.6647298345772276, 0.6663598560505134, 0.6679898775237992, 0.6696198989970853, 0.6712499204703711, 0.672879941943657, 0.6745192534487983,
0.676167613279076, 0.6778159731093539, 0.6794643329396317, 0.6811126927699096, 0.6827610526001873, 0.6844117505708202, 0.6860794888387595, 0.6877472271066991, 0.6894149653746385, 0.6910827036425778,
0.6927504419105173, 0.6944181801784567, 0.6961024041828838, 0.6977905222412472, 0.6994786402996106, 0.7011667583579737, 0.7028548764163371, 0.7045429944747005, 0.7062434625444614, 0.7079531190945869,
0.7096627756447124, 0.7113724321948379, 0.7130820887449636, 0.7147917452950892, 0.7165108611022232, 0.7182432335394007, 0.7199756059765782, 0.7217079784137556, 0.7234403508509332, 0.7251727232881108,
0.726913284213315, 0.7286697282039188, 0.7304261721945224, 0.7321826161851263, 0.7339390601757299, 0.7356955041663336, 0.7374608073975087, 0.7392427673995341, 0.7410247274015596, 0.7428066874035849,
0.7445886474056106, 0.746370607407636, 0.7481644491068483, 0.7499734100827669, 0.7517823710586856, 0.7535913320346042, 0.7554002930105226, 0.7572092539864412, 0.759036006219914, 0.7608736136711696,
0.7627112211224254, 0.7645488285736812, 0.766386436024937, 0.7682240434761924, 0.7700888541550648, 0.7719569315027456, 0.7738250088504262, 0.7756930861981068, 0.7775611635457873, 0.7794375904332373,
0.781338036475358, 0.7832384825174789, 0.7851389285595997, 0.7870393746017206, 0.7889398206438413, 0.790865105350138, 0.7928000934330446, 0.7947350815159508, 0.7966700695988573, 0.7986050576817636,
0.8005503048683515, 0.8025220514306302, 0.8044937979929087, 0.8064655445551875, 0.8084372911174661, 0.810409037679745, 0.812417678319383, 0.8144286521744348, 0.8164396260294864, 0.8184505998845378,
0.8204615737395896, 0.8225021385054793, 0.8245550208725887, 0.8266079032396979, 0.8286607856068072, 0.8307136679739168, 0.8327925284171482, 0.834890316314536, 0.8369881042119236, 0.8390858921093111,
0.841183680006699, 0.8433083500192712, 0.845454082798177, 0.8475998155770829, 0.8497455483559885, 0.8518912811348943, 0.8540707035577115, 0.8562678716444292, 0.8584650397311465, 0.8606622078178642,
0.8628593759045816, 0.8651043067759017, 0.8673567472565732, 0.8696091877372444, 0.8718616282179158, 0.8741253722147707, 0.8764370427062623, 0.8787487131977542, 0.8810603836892454, 0.8833720541807374,
0.8857243150309401, 0.8880996779369259, 0.8904750408429121, 0.8928504037488978, 0.8952398736400787, 0.8976837731247654, 0.900127672609452, 0.902571572094139, 0.9050154715788258, 0.9075257986507934,
0.9100436173602886, 0.9125614360697839, 0.9150792547792795, 0.9176542033927435, 0.920251598757859, 0.9228489941229744, 0.9254463894880901, 0.9281010063043421, 0.9307844127580285, 0.9334678192117154,
0.9361512256654021, 0.9394102036102308, 0.9428687525888874, 0.9463273015675442, 0.9490381673258316, 0.9514270266119649, 0.9538158858980986, 0.9562047451842322, 0.9587683394022021, 0.9617544751544383,
0.9647406109066744, 0.9677267466589108, 0.9708036235155444, 0.9739079902539933, 0.9770123569924426, 0.9801652025890528, 0.9833982694377071, 0.9866313362863612, 0.9898813019983241, 0.993254201332216,
0.9966271006661077, 1 };

const double fov = 1.658062789;
const int sunex_length = sizeof(AngleToHeightNormalized) / sizeof(double);
const int reverse_length = sizeof(HeightToAngleNormalized) / sizeof(double);

double sunex(double phi)
{
	if (isnan(phi) || isinf(phi))
	{
		return 0.0;
	}
	double tc = abs(phi) / fov;
	if (tc >= 1.0)
		return AngleToHeightNormalized[sunex_length - 1];
	else if (tc <= 0.0)
		return  AngleToHeightNormalized[0];
	else
	{
		double i = tc * (sunex_length - 1);
		int i1 = (int)floor(i);
		int i2 = i1 + 1;
		return  AngleToHeightNormalized[i1] * (i2 - i) + AngleToHeightNormalized[i2] * (i - i1);
	}
}

double reverseSunex(double r)
{
	if (isnan(r) || isinf(r))
	{
		return 0.0;
	}
	if (r >= 1.0)
	{
		return fov * HeightToAngleNormalized[reverse_length - 1];
	}
	else if (r <= 0)
	{
		return fov * HeightToAngleNormalized[0];
	}
	else
	{
		double i = r * (reverse_length - 1);
		int i1 = floor(i);
		int i2 = i1 + 1;
		return fov * (HeightToAngleNormalized[i1] * (i2 - i) + HeightToAngleNormalized[i2] * (i - i1));
	}
}
