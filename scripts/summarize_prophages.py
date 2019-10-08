import csv



dataset=["/home/icaro/Documentos/WGCA/prophage_prediction/V583/prophage_coordinates.tsv","/home/icaro/Documentos/WGCA/prophage_prediction/OG1RF/prophage_coordinates.tsv"]

print("Saving file to tsv format...")
head = ["SAMPLE","NUMBER_PROPHAGES"]
# write file
with open('prophage_prediction/summary.tsv', 'w', newline='') as f_output:
    tsv_output = csv.writer(f_output, delimiter='\t')
    tsv_output.writerow(head)
    for i in dataset:
        filepath=i
        #get number of prophages
        n_prophages = len(open(filepath).readlines(  ))

        #get filename alias
        sample = filepath.split("/")[-2]
        data = [sample, n_prophages]
        print("sample:",sample," | prophages:",n_prophages)
        tsv_output.writerow(data)

print("Done!")
