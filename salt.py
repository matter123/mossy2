import hashlib
import time
import fractions
# 0 is sunday, 6 is saturday
# ('Name', 'symbol', (ox states), group(dayof week for non hash)),
cations = [
    ('Hydronium',	'H₃0', (1,),		0),
    ('Lithium',		'li', (1,),			0),
    ('Beryllium',	'Be', (2,),			1),
    ('Boron',		'B',  (3,),			5),
    ('Ammonium',	'NH₄', (1,),        5),
    ('Sodium',		'Na', (1,),			0),
    ('Magnesium',	'Mg', (2,),			1),
    ('Aluminum',	'Al', (3,), 		5),
    ('Silicon',		'Si', (4,),			5),
    ('Potassium',	'K',  (1),			0),
    ('Calcium',		'Ca', (2,),			1),
    ('Scandium',	'Sc', (3,),			4),
    ('Titanium',	'Ti', (3, 4),		4),
    ('Vanadium',	'V',  (5, 4, 3, 2),	4),
    ('Chromium',	'Cr', (3, 6, 2),	4),
    ('Maganese',	'Mn', (2, 7, 6, 4, 3), 	4),
    ('Iron',		'Fe', (3, 2),		4),
    ('Cobalt',		'Co', (3, 2),		4),
    ('Nickel',		'Ni', (3, 2),		4),
    ('Copper',		'Cu', (2, 1),		4),
    ('Zinc',		'Zn', (2,),			4),
    ('Gallium',		'Ga', (3,),			5),
    ('Germanium',	'Ge', (3,),			6),
    ('Arsenic',		'As', (3, 5),		6),
    ('Rubidium',	'Rb', (1,),			0),
    ('Strontium',	'Sr', (2,),			1),
    ('Yttrium',		'Y',  (3,),			4),
    ('Zirconium',	'Zr', (4,),			4),
    ('Niobium',		'Nb', (5, 3),		4),
    ('Molybdenum',	'Mo', (6, 5, 4, 3, 2),	4),
    ('Technetium',	'Tc', (7,),			4),
    ('Ruthenium',	'Ru', (3, 4, 2, 6, 8),	4),
    ('Rhodium',		'Rh', (3, 2, 4),	4),
    ('Palladium',	'Pd', (2, 4),		4),
    ('Silver',		'Ag', (1,),			4),
    ('Cadmium',		'Cd', (2,),			4),
    ('Indium',		'In', (3,),			5),
    ('Tin',			'Sn', (4, 6),		5),
    ('Antimony',	'Sb', (3, 5),		6),
    ('Tellurium',	'Te', (2,),			6),
    ('Caesium',		'Cs', (1,),			0),
    ('Barium',		'Ba', (2,),			1),
    ('Lanthanum',	'La', (3,),			2),
    ('Cerium',		'Ce', (3, 4),		2),
    # Praseodymium is skipped, it is not fun to say
    ('Neodymium',	'Nd', (3,),			2),
    ('Promethium',	'Pm', (3,),			2),
    ('Samarium',	'Sm', (3, 2),		2),
    ('Europium',	'Eu', (3, 2),		2),
    ('Gadolinium',	'Gd', (3,),			2),
    ('Terbium',		'Tb', (3, 4),		2),
    ('Dysprosium',	'Dy', (3,),			2),
    ('Holmium',		'Ho', (3,),			2),
    ('Erbium',		'Er', (3,),			2),
    ('Thulium',		'Tm', (3, 2),		2),
    ('Gadolinium',	'Gd', (3, 2),		2),
    ('Lutetium',	'Lu', (3,),			2),
    ('Hafnium',		'Hf', (4,),			4),
    ('Tantalum',	'Ta', (5,),			4),
    ('Tungsten',	'W',  (6, 5, 4, 3, 2),	4),
    ('Rhenium',		'Re', (7, 6, 4, 2),		4),
    ('Osmium',		'Os', (4, 2, 3, 6, 8),	4),
    ('Iridium',		'Ir', (4, 2, 3, 6),	4),
    ('Platnium',	'Pt', (4, 2),		4),
    ('Gold',		'Au', (3, 1),		4),
    ('Mercury(II)',	'Hg', (2,),			4),
    ('Mercury(I)',	'Hg₂', (2,),		4),
    ('Thallium',	'Th', (1, 3),		5),
    ('Lead',		'Pb', (2, 4),		5),
    ('Bismuth',		'Bi', (3, 5),		5),
    ('Polonium',	'Po', (4, 2, 6),	6),
    ('Francium',	'Fr', (1,),			0),
    ('Radium',		'Ra', (2,),			1),
    ('Actinium',	'Ac', (3,),			3),
    ('Thorium',		'Th', (4,),			3),
    # Protactinium is skipped, it is not fun to say
    ('Uranium',		'U',  (6, 5, 4, 3), 3),
    ('Neptunium',	'Np', (5, 6, 4, 3),	3),
    ('Plutonium',	'Pu', (4, 6, 5, 3),	3),
    ('Americium',	'Am', (3, 6, 5, 4),	3),
    ('Curium',		'Cm', (3,),			3),
    ('Berkelium',	'Bk', (3, 4),		3),
    ('Californium',	'Cf', (3,),			3),
    ('Einsteinium',	'Es', (3,),			3),
    ('Fermium',		'Fm', (3,),			3),
    ('Mendelevium',	'Md', (3),			3),
    ('Nobelium',	'No', (3, 2),		3),
    ('Lawrencium',	'Lr', (3,),			3),
    ('Rutherfordium', 'Rf', (4,),		4),
    ('Dubnium',		'Db', (5,),			4),
    ('Seaborgium',	'Sg', (6,),			4),
    ('Bohrium',		'Bh', (7,),			4),
    ('Hassium',		'Hs', (8,),			4),
]
# ('Name', 'symbol', ox state),
anions = [
    ('Hydride', 	'H',	1),
    ('Fluoride', 	'F',	1),
    ('Chloride', 	'Cl',	1),
    ('Bromide', 	'Br',	1),
    ('Iodide',	 	'I',	1),
    ('Oxide',	 	'O',	2),
    ('Sulfide',	 	'S',	2),
    ('Selenide', 	'Se',	2),
    ('Telluride', 	'Te',	2),
    ('Nitride',	 	'N',	3),
    ('Phosphide',	'P',	3),
    ('Arsenide', 	'As',	3),
    ('Carbide',	 	'C',	4),
    ('Silicide', 	'Si',	4),
    ('Cyanide',		'CN',	1),
    ('Hydroxide',	'OH',	1),
    ('Hypochlorite', 'ClO',	1),
    ('Hypobromite',	'BrO',	1),
    ('Hypoiodite',	'IO',	1),
    ('Chlorite',	'ClO₂',	1),
    ('Bromite',		'BrO₂',	1),
    ('Iodite',		'IO₂',	1),
    ('Bisulfite',	'HSO₃',	1),
    ('Nitrite',		'NO₂',	1),
    ('Sulfite',		'SO₃',	2),
    ('Chlorate',	'ClO₃',	1),
    ('Bromate',		'BrO₃',	1),
    ('Iodate',		'IO₃',	1),
    ('Perchlorate',	'ClO₄',	1),
    ('Perbromate',	'BrO₄',	1),
    ('Periodate',	'IO₄',	1),
    ('Bicarbonate',	'HCO₃',	1),
    ('Bisulfate',	'HSO₄',	1),
    ('Dihydrogen phosphate', 'H₂PO₄', 1),
    ('Acetate', 	'C₂H₃O₂',	1),
    ('Nitrate',		'NO₃',	1),
    ('Permanganate', 'MnO₄', 1),
    ('Thiocyanate',	'SCN',	1),
    ('Carbonate',	'CO₃',	2),
    ('Chromate',	'CrO₄',	2),
    ('Dichromate',	'Cr₂O₇', 2),
    ('Hydrogen phosphate', 'HPO₄', 2),
    ('Oxalate',		'C₂O₄',	2),
    ('Sulfate',		'SO₄',	2),
    ('Thiosulfate',	'S₂O₃',	2),
    ('Borate',		'BO₃',	3),
    ('Phosphate',	'PO₄',	3),
    ('Arsenate',	'AsO₄',	3),
    ('Tetraborate',	'B₄O₇',	2),
    ('Tartate',		'C₄H₄O₆', 2),
    ('Binoxalate',	'HC₂O₄', 1),
    ('Hydrogen Sulfide', 'HS', 1),
    ('Amide',		'NH₂',	1),
    ('Peroxide',	'O₂',	2),
    ('Hexafluorosilicate', 'SiF₆', 2),
    ('Silicate',	'SiO₃',	2),
    ('Silicate',	'SiO₄',	2),
]


def get_anion(sha_hash):
    anion = int(sha_hash[20:], 16)
    return anions[anion % len(anions)]


def get_cation(sha_hash):
    sha_hash = sha_hash[:20]
    group = [f for f in cations if f[3] == int(sha_hash[:5], 16) % 7]
    cation = group[int(sha_hash[5:15], 16) % len(group)]
    if len(cation[2]) > 1:
        roman = ['I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII']
        charge = cation[2][int(sha_hash[15:], 16) % len(cation[2])]
        return (cation[0] + '(' + roman[charge-1] + ')', cation[1], charge)
    return (cation[0], cation[1], cation[2][0])

def make_salt(digest):
    salt = (get_cation(digest),
            get_anion(digest))
    paren = [False, False]
    subscript = "₀ ₂₃₄₅₆₇₈₉"
    for sub in subscript:
        if sub in salt[0][1]:
            paren[0] = True
        if sub in salt[1][1]:
            paren[1] = True
    if sum(1 for c in salt[0][1] if c.isupper()) is not 1:
        paren[0] = True
    if sum(1 for c in salt[1][1] if c.isupper()) is not 1:
        paren[1] = True
    name = salt[0][0] + " " + salt[1][0]
    formula_parts = [salt[0][1], salt[1][1], salt[1][2], salt[0][2]]
    if paren[0]:
        formula_parts[0] = "(" + formula_parts[0] + ")"
    if paren[1]:
        formula_parts[1] = "(" + formula_parts[1] + ")"
    formula_parts[2] = formula_parts[2]//fractions.gcd(formula_parts[2],
                                                       formula_parts[3])
    formula_parts[3] = formula_parts[3]//fractions.gcd(formula_parts[2],
                                                       formula_parts[3])
    formula = ''.join([f for f in (formula_parts[0] +
                       subscript[formula_parts[2]] +
                       formula_parts[1] +
                       subscript[formula_parts[3]]) if not f == ' '])
    return (name,formula)
