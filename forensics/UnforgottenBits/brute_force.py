from itertools import permutations
from concurrent.futures import ProcessPoolExecutor
import subprocess

# Champion list (spaces removed for steghide)
champions = [c.replace(" ", "") for c in [
    "Aatrox","Ahri","Akali","Akshan","Alistar","Amumu","Anivia","Annie","Aphelios",
    "Ashe","AurelionSol","Azir","Bard","Bel’Veth","Blitzcrank","Brand","Braum",
    "Caitlyn","Camille","Cassiopeia","Cho’Gath","Corki","Darius","Diana","Dr.Mundo",
    "Draven","Ekko","Elise","Evelynn","Ezreal","Fiddlesticks","Fiora","Fizz","Galio",
    "Gangplank","Garen","Gnar","Gragas","Graves","Gwen","Hecarim","Heimerdinger",
    "Illaoi","Irelia","Ivern","Janna","JarvanIV","Jax","Jayce","Jhin","Jinx",
    "Kai’Sa","Kalista","Karma","Karthus","Kassadin","Katarina","Kayle","Kayn",
    "Kennen","Kha’Zix","Kindred","Kled","Kog’Maw","LeBlanc","LeeSin","Leona",
    "Lillia","Lissandra","Lucian","Lulu","Lux","Malphite","Malzahar","Maokai",
    "MasterYi","Milio","MissFortune","Mordekaiser","Morgana","Nami","Nasus",
    "Nautilus","Neeko","Nidalee","Nilah","Nocturne","Nunu&Willump","Olaf",
    "Orianna","Ornn","Pantheon","Poppy","Pyke","Qiyana","Quinn","Rakan","Rammus",
    "Rek’Sai","Rell","Renekton","Rengar","Riven","Rumble","Ryze","Samira","Senna",
    "Seraphine","Set","Shen","Shyvana","Singed","Sion","Sivir","Skarner","Sona",
    "Soraka","Swain","Sylas","Syndra","TahmKench","Taliyah","Talon","Taric","Teemo",
    "Thresh","Tristana","Trundle","Tryndamere","TwistedFate","Twitch","Udyr","Urgot",
    "Varus","Vayne","Veigar","Vel'Koz","Vex","Vi","Viktor","Vladimir","Volibear",
    "Warwick","Wukong","Xayah","Xerath","XinZhao","Yasuo","Yone","Yorick","Yuumi",
    "Zac","Zed","Zeri","Ziggs","Zilean","Zoe","Zyra"
]]

bmp_file = "vol4-3.home.yone.gallery.7.bmp"

def try_password(champs):
    password = f"yasuoaatrox{champs[0].lower()}{champs[1].lower()}"
    print(f"Trying: {password}")
    try:
        result = subprocess.run(
            ["steghide", "info", bmp_file, "-p", password],
            capture_output=True, text=True
        )
        output = result.stdout + result.stderr
        if "could not extract any data" not in output:
            return password, output
    except Exception as e:
        print("Error:", e)
    return None

if __name__ == "__main__":
    from itertools import permutations
    from concurrent.futures import ProcessPoolExecutor

    perms = list(permutations(champions, 2))

    with ProcessPoolExecutor(max_workers=8) as executor:
        for res in executor.map(try_password, perms):
            if res:
                print("Possible password found:", res[0])
                print(res[1])
                break
