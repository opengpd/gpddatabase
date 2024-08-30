from gpddatabase.data_objects.markdown.MarkdownDataObjectData import MarkdownDataObjectData as MarkdownFunctionalities

from gpddatabase.exceptions.Exceptions import ExceptionNoField
from gpddatabase.exceptions.Exceptions import ExceptionWrongType
from gpddatabase.exceptions.Exceptions import ExceptionWrongLength
from gpddatabase.exceptions.Exceptions import ExceptionWrongLabel
from gpddatabase.exceptions.Exceptions import ExceptionNotUnique
from gpddatabase.exceptions.Exceptions import ExceptionUnknownLabel

from gpddatabase.data_objects.DataObjectDataSet import DataObjectDataSet

class DataObjectData(MarkdownFunctionalities):

	'''Class representing data object.'''

	def __init__(self, data):

		#get
		self.data_sets = {}

		for i_element, element in enumerate(data):

			#only data groups
			if 'data_set' not in element:
				continue

			#get label
			if 'label' in element['data_set']:

				label = element['data_set']['label']

				if label is None:
					raise ExceptionNoField('label')

				if not isinstance(label, str):
					raise ExceptionWrongType('label')

				if len(label) > 20:
					raise ExceptionWrongLength('label', 20)

				if not label.replace('_', '').isalnum():
					raise ExceptionWrongLabel(label)

			else:
				label = 'data_set_' + str(i_element)

			#store
			if label in self.data_sets:
				raise ExceptionNotUnique(label)

			self.data_sets.update({label: DataObjectDataSet(element['data_set'], label)})

	def get_data_sets(self):

		'''Get all data groups.'''

		return self.data_sets

	def get_data_set_labels(self):

		'''Get data set labels.'''

		return list(self.data_sets.keys())

	def get_data_set(self, label):

		'''Get a given data set by label.'''

		if label not in self.data_sets:
			raise ExceptionUnknownLabel(label)

		return self.data_sets[label]
