import os
from docx import Document

def merge_docx_files(folder_path, output_file):
    # Create a new Document object for the merged file
    merged_document = Document()

    # Loop through all files in the folder
    for filename in os.listdir(folder_path):
        # Only process .docx files
        if filename.endswith('.docx'):
            file_path = os.path.join(folder_path, filename)
            doc = Document(file_path)
            
            # Append each paragraph to the merged document
            for paragraph in doc.paragraphs:
                merged_document.add_paragraph(paragraph.text)
            
            # Optionally add a page break between documents
            merged_document.add_page_break()

    # Save the merged document
    merged_document.save(output_file)
    print(f"All files merged into '{output_file}' successfully.")

# Usage
folder_path = './'
output_file = './DataMining_12212070.docx' 
merge_docx_files(folder_path, output_file)