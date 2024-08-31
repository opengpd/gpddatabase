'''Create data file markdown pages.'''

import gpddatabase

exclusiveDatabase = gpddatabase.ExclusiveDatabase()
exclusiveDatabase.convert_to_markdown('docs')
